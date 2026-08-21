#include <fstream>
#include <string>

using json = nlohmann::json;


// ------------------------------------------------------------
// SAVE CAMERA
// ------------------------------------------------------------

bool saveCamera(
    const Camera& camera,
    const std::string& filename)
{
    if (camera.location == nullptr)
        return false;

    json j;

    j["location"] = {
        {"x", camera.location->x},
        {"y", camera.location->y},
        {"z", camera.location->z}
    };

    j["rotation"] = {
        {"x", camera.rotationX},
        {"y", camera.rotationY},
        {"z", camera.rotationZ}
    };

    j["casting"] = {
        {"rX", camera.rX},
        {"rY", camera.rY},
        {"rZ", camera.rZ}
    };

    std::ofstream file(filename);

    if (!file.is_open())
        return false;

    file << j.dump(4);

    return true;
}


// ------------------------------------------------------------
// LOAD CAMERA
// ------------------------------------------------------------

bool loadCamera(
    Camera& camera,
    const std::string& filename)
{
    std::ifstream file(filename);

    if (!file.is_open())
        return false;

    try
    {
        json j;
        file >> j;

        // Make sure location exists.
        if (camera.location == nullptr)
            camera.location = new Point3D();

        // Location
        if (j.contains("location"))
        {
            camera.location->x =
                j["location"].value("x", 0.0f);

            camera.location->y =
                j["location"].value("y", 0.0f);

            camera.location->z =
                j["location"].value("z", 0.0f);
        }

        // Rotation
        if (j.contains("rotation"))
        {
            camera.rotationX =
                j["rotation"].value("x", 0.0f);

            camera.rotationY =
                j["rotation"].value("y", 0.0f);

            camera.rotationZ =
                j["rotation"].value("z", 0.0f);
        }

        // Casting values
        if (j.contains("casting"))
        {
            camera.rX =
                j["casting"].value("rX", camera.rX);

            camera.rY =
                j["casting"].value("rY", camera.rY);

            camera.rZ =
                j["casting"].value("rZ", camera.rZ);
        }

        return true;
    }
    catch (const json::exception& e)
    {
        fprintf(
            stderr,
            "Camera JSON error: %s\n",
            e.what()
        );

        return false;
    }
}
