#include <fstream>
#include <string>

using json = nlohmann::json;


// ------------------------------------------------------------
// SAVE
// ------------------------------------------------------------

bool savePointCloud(
    const PointCloud& cloud,
    const std::string& filename)
{
    json j;

    // Points
    j["points"] = json::array();

    for (const Point3D& p : cloud.points)
    {
        j["points"].push_back({
            {"x", p.x},
            {"y", p.y},
            {"z", p.z}
        });
    }


    // Edges
    j["edges"] = json::array();

    for (const Edge& e : cloud.edges)
    {
        j["edges"].push_back({
            {"a", e.a},
            {"b", e.b}
        });
    }


    // Points2
    j["points2"] = json::array();

    for (const Point3D& p : cloud.points2)
    {
        j["points2"].push_back({
            {"x", p.x},
            {"y", p.y},
            {"z", p.z}
        });
    }


    // Colours
    j["colours"] = cloud.colours;
    j["pointcolours"] = cloud.pointcolours;

    j["render_vertices"] = cloud.render_vertices;


    // Rotation
    j["rotation"] = {
        {"x", cloud.rotationX},
        {"y", cloud.rotationY},
        {"z", cloud.rotationZ}
    };


    // Scale
    j["scale"] = {
        {"x", cloud.scaleX},
        {"y", cloud.scaleY},
        {"z", cloud.scaleZ}
    };


    // Position
    j["position"] = {
        {"x", cloud.positionX},
        {"y", cloud.positionY},
        {"z", cloud.positionZ}
    };


    std::ofstream file(filename);

    if (!file.is_open())
        return false;

    // 4-space formatted JSON
    file << j.dump(4);

    return true;
}


// ------------------------------------------------------------
// LOAD
// ------------------------------------------------------------

bool loadPointCloud(
    PointCloud& cloud,
    const std::string& filename)
{
    std::ifstream file(filename);

    if (!file.is_open())
        return false;

    try
    {
        json j;

        file >> j;


        // Clear existing geometry.
        cloud.points.clear();
        cloud.edges.clear();
        cloud.points2.clear();
        cloud.colours.clear();
        cloud.pointcolours.clear();


        // Points
        if (j.contains("points"))
        {
            for (const auto& p : j["points"])
            {
                cloud.points.push_back({
                    p.value("x", 0.0f),
                    p.value("y", 0.0f),
                    p.value("z", 0.0f)
                });
            }
        }


        // Edges
        if (j.contains("edges"))
        {
            for (const auto& e : j["edges"])
            {
                cloud.edges.push_back({
                    e.value("a", 0),
                    e.value("b", 0)
                });
            }
        }


        // Points2
        if (j.contains("points2"))
        {
            for (const auto& p : j["points2"])
            {
                cloud.points2.push_back({
                    p.value("x", 0.0f),
                    p.value("y", 0.0f),
                    p.value("z", 0.0f)
                });
            }
        }


        // Colours
        if (j.contains("colours"))
        {
            cloud.colours =
                j["colours"].get<std::vector<int>>();
        }

        if (j.contains("pointcolours"))
        {
            cloud.pointcolours =
                j["pointcolours"].get<std::vector<int>>();
        }


        cloud.render_vertices =
            j.value("render_vertices", true);


        // Rotation
        if (j.contains("rotation"))
        {
            cloud.rotationX =
                j["rotation"].value("x", 0.0f);

            cloud.rotationY =
                j["rotation"].value("y", 0.0f);

            cloud.rotationZ =
                j["rotation"].value("z", 0.0f);
        }


        // Scale
        if (j.contains("scale"))
        {
            cloud.scaleX =
                j["scale"].value("x", 1.0f);

            cloud.scaleY =
                j["scale"].value("y", 1.0f);

            cloud.scaleZ =
                j["scale"].value("z", 1.0f);
        }


        // Position
        if (j.contains("position"))
        {
            cloud.positionX =
                j["position"].value("x", 0.0f);

            cloud.positionY =
                j["position"].value("y", 0.0f);

            cloud.positionZ =
                j["position"].value("z", 0.0f);
        }


        return true;
    }
    catch (const json::exception& e)
    {
        fprintf(
            stderr,
            "PointCloud JSON error: %s\n",
            e.what()
        );

        return false;
    }
}
