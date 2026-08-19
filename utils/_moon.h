
#include <cmath>

constexpr double PI = 3.14159265358979323846;

// -----------------------------------------------------
// MOON ORBIT APPROXIMATION
// -----------------------------------------------------

struct Vec3
{
    double x, y, z;
};

static Vec3 normalize(const Vec3& v)
{
    double m = std::sqrt(v.x*v.x + v.y*v.y + v.z*v.z);
    return { v.x/m, v.y/m, v.z/m };
}

// rough circular orbit approximation
static Vec3 moonPosition(double jd)
{
    double days = jd - 2451545.0;

    // lunar orbital period ~27.321 days
    double angle = 2.0 * PI * std::fmod(days, 27.321582);

    double dist = 384400000.0; // meters (average)

    return {
        dist * std::cos(angle),
        dist * std::sin(angle),
        0.0
    };
}

// -----------------------------------------------------
// TIDAL FORCE VECTOR (per unit mass)
// -----------------------------------------------------

static Vec3 moonTidalAcceleration(double jd)
{
    Vec3 moon = moonPosition(jd);

    double r = std::sqrt(moon.x*moon.x + moon.y*moon.y + moon.z*moon.z);

    // normalize direction
    Vec3 dir = normalize(moon);

    // tidal strength ∝ 1 / r^3
    double G = 6.67430e-11;
    double Mmoon = 7.342e22;

    double strength = G * Mmoon / (r * r * r);

    return {
        dir.x * strength,
        dir.y * strength,
        dir.z * strength
    };
}
