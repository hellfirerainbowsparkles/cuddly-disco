#include <array>
#include <cmath>
#include <cstdlib>
#include <filesystem>
#include <fstream>
#include <limits>
#include <string>

struct Location
{
    float latitude;
    float longitude;
};



Location GetSystemLocation()
{
    const char* filename = "/tmp/ip_location.json";

    // Download JSON using wget
    int result = std::system(
        "wget -q -O /tmp/ip_location.json http://ip-api.com/json/"
    );

    if (result != 0 || !std::filesystem::exists(filename))
        return {0.0f, 0.0f};

    std::ifstream file(filename);

    if (!file)
        return {0.0f, 0.0f};

    nlohmann::json json;
    file >> json;

    file.close();

    std::filesystem::remove(filename);

    if (!json.contains("lat") || !json.contains("lon"))
        return {0.0f, 0.0f};

    return {
        json["lat"].get<float>(),
        json["lon"].get<float>()
    };
}

struct MagneticField
{
    double north; // nT
    double east;  // nT
    double down;  // nT
};

MagneticField negateField(const MagneticField& field)
{
    return {
        -field.north,
        -field.east,
        -field.down
    };
}

/*
 * Input:
 * fields[0] = external field
 * fields[1] = surface/total field
 * fields[2] = internal field
 *
 * Output:
 * cancellation[0] = field cancelling external
 * cancellation[1] = field cancelling surface/total
 * cancellation[2] = field cancelling internal
 */
std::array<MagneticField, 3> calculateCancellationFields(
    const std::array<MagneticField, 3>& fields)
{
    return {
        negateField(fields[0]),
        negateField(fields[1]),
        negateField(fields[2])
    };
}



enum FieldIndex
{
    ExternalField = 0,
    TotalField    = 1,
    InternalField = 2
};

namespace GeospaceApprox
{
    constexpr double PI = 3.14159265358979323846;

    constexpr double EARTH_RADIUS_KM = 6371.2;

    // Approximate equatorial surface strength.
    constexpr double EQUATORIAL_FIELD_NT = 30000.0;

    double degToRad(double degrees)
    {
        return degrees * PI / 180.0;
    }

    MagneticField add(
        const MagneticField& a,
        const MagneticField& b)
    {
        return {
            a.north + b.north,
            a.east  + b.east,
            a.down  + b.down
        };
    }

    /*
     * Simplified internal dipole field.
     *
     * This is not a complete WMM2025 implementation.
     * It returns an aligned-dipole field in local NED coordinates.
     */
    MagneticField calculateInternalField(
        double latitudeDeg,
        double heightKm)
    {
        const double latitude = degToRad(latitudeDeg);

        const double radius =
        EARTH_RADIUS_KM + heightKm;

        const double radialScale =
        std::pow(EARTH_RADIUS_KM / radius, 3.0);

        /*
         * Local field for an approximately axis-aligned dipole:
         *
         * north = B0 * cos(latitude)
         * down  = 2 B0 * sin(latitude)
         */
        const double north =
        EQUATORIAL_FIELD_NT *
        radialScale *
        std::cos(latitude);

        const double down =
        2.0 *
        EQUATORIAL_FIELD_NT *
        radialScale *
        std::sin(latitude);

        return {
            north,
            0.0,
            down
        };
    }

    double downloadLatestDst()
    {
        const std::string filename =
        "/tmp/noaa_geospace_dst.json";

        const std::string command =
        "wget -q --timeout=15 --tries=2 "
        "-O " + filename + " "
        "\"https://services.swpc.noaa.gov/json/geospace/"
        "geospace_dst_1_hour.json\"";

        const int result = std::system(command.c_str());

        if (result != 0 ||
            !std::filesystem::exists(filename))
        {
            return std::numeric_limits<double>::quiet_NaN();
        }

        try
        {
            std::ifstream file(filename);

            if (!file)
                return std::numeric_limits<double>::quiet_NaN();

            nlohmann::json data;
            file >> data;

            file.close();
            std::filesystem::remove(filename);

            if (!data.is_array() || data.empty())
                return std::numeric_limits<double>::quiet_NaN();

            /*
             * Search backward because the last record could occasionally
             * contain a null or invalid value.
             */
            for (auto it = data.rbegin(); it != data.rend(); ++it)
            {
                if (it->contains("dst") &&
                    !(*it)["dst"].is_null() &&
                    (*it)["dst"].is_number())
                {
                    return (*it)["dst"].get<double>();
                }
            }
        }
        catch (...)
        {
            std::filesystem::remove(filename);
        }

        return std::numeric_limits<double>::quiet_NaN();
    }

    /*
     * Converts global Dst into a rough local external-field vector.
     *
     * This is an approximation, not the complete NOAA SWMF spatial output.
     */
    MagneticField estimateExternalField(
        double latitudeDeg,
        double longitudeDeg,
        double dstNT)
    {
        const double latitude = degToRad(latitudeDeg);
        const double longitude = degToRad(longitudeDeg);

        /*
         * Ring-current disturbances are most strongly represented at
         * low and middle geomagnetic latitudes.
         */
        const double latitudeFactor =
        std::pow(std::cos(latitude), 2.0);

        /*
         * Small longitude modulation representing local-time asymmetry.
         * This is heuristic; a complete model requires UTC, solar-wind
         * vectors, ionospheric currents and magnetospheric position.
         */
        const double longitudeFactor =
        1.0 + 0.15 * std::cos(longitude);

        const double disturbance =
        dstNT *
        latitudeFactor *
        longitudeFactor;

        /*
         * Negative Dst generally means a reduction of the horizontal
         * field. In local NED coordinates, place the basic disturbance
         * in the north component.
         */
        return {
            disturbance,
            0.0,
            0.0
        };
    }
}

/*
 * Returns:
 *
 * result[0] = external disturbance field, nT
 * result[1] = total local field, nT
 * result[2] = internal Earth field, nT
 *
 * Coordinates:
 * latitudeDeg  = -90 ... +90
 * longitudeDeg = -180 ... +180
 * heightKm     = height above Earth's surface
 */
std::array<MagneticField, 3> getGeomagneticFields(
    float latitudeDeg,
    float longitudeDeg,
    float heightKm = 0.0f)
{
    const double nan =
    std::numeric_limits<double>::quiet_NaN();

    if (!std::isfinite(latitudeDeg) ||
        !std::isfinite(longitudeDeg) ||
        !std::isfinite(heightKm) ||
        latitudeDeg < -90.0f ||
        latitudeDeg > 90.0f ||
        longitudeDeg < -180.0f ||
        longitudeDeg > 180.0f ||
        heightKm <= -GeospaceApprox::EARTH_RADIUS_KM)
    {
        const MagneticField invalid{nan, nan, nan};

        return {
            invalid,
            invalid,
            invalid
        };
    }

    const MagneticField internal =
    GeospaceApprox::calculateInternalField(
        latitudeDeg,
        heightKm);

    const double dst =
    GeospaceApprox::downloadLatestDst();

    MagneticField external{0.0, 0.0, 0.0};

    if (std::isfinite(dst))
    {
        external =
        GeospaceApprox::estimateExternalField(
            latitudeDeg,
            longitudeDeg,
            dst);
    }

    const MagneticField total =
    GeospaceApprox::add(internal, external);

    return {
        external,
        total,
        internal
    };
}
