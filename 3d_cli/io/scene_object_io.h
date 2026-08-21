#include <fstream>
#include <string>
#include <vector>

using json = nlohmann::json;


// ------------------------------------------------------------
// SAVE SCENE OBJECT
// ------------------------------------------------------------

bool saveSceneObject(
    const SceneObject& scene,
    const std::string& sceneFilename,
    const std::string& cameraFilename,
    const std::vector<std::string>& pointcloudFilenames)
{
    if (pointcloudFilenames.size() != scene.pointclouds.size())
        return false;

    // Save camera into its own JSON file.
    if (!saveCamera(
            scene.camera,
            cameraFilename))
    {
        return false;
    }

    // Save each pointcloud into its own JSON file.
    for (size_t i = 0;
         i < scene.pointclouds.size();
         ++i)
    {
        if (!savePointCloud(
                scene.pointclouds[i],
                pointcloudFilenames[i]))
        {
            return false;
        }
    }

    json j;

    // Store references to the external files.
    j["camera"] = cameraFilename;
    j["pointclouds"] = pointcloudFilenames;

    // Scene-specific data.
    j["colours_collection"] =
        scene.colours_collection;

    j["colour_index"] =
        scene.colour_index;

    j["use_scene_colours"] =
        scene.use_scene_colours;

    std::ofstream file(sceneFilename);

    if (!file.is_open())
        return false;

    file << j.dump(4);

    return true;
}


// ------------------------------------------------------------
// LOAD SCENE OBJECT
// ------------------------------------------------------------

bool loadSceneObject(
    SceneObject& scene,
    const std::string& sceneFilename,
    std::string& cameraFilename,
    std::vector<std::string>& pointcloudFilenames)
{
    std::ifstream file(sceneFilename);

    if (!file.is_open())
        return false;

    try
    {
        json j;

        file >> j;

        // ----------------------------------------------------
        // Read camera filename
        // ----------------------------------------------------

        cameraFilename =
            j.value(
                "camera",
                std::string()
            );

        if (cameraFilename.empty())
            return false;


        // ----------------------------------------------------
        // Load camera
        // ----------------------------------------------------

        if (!loadCamera(
                scene.camera,
                cameraFilename))
        {
            return false;
        }


        // ----------------------------------------------------
        // Read pointcloud filenames
        // ----------------------------------------------------

        pointcloudFilenames.clear();

        if (j.contains("pointclouds"))
        {
            pointcloudFilenames =
                j["pointclouds"]
                .get<std::vector<std::string>>();
        }


        // ----------------------------------------------------
        // Load pointclouds
        // ----------------------------------------------------

        scene.pointclouds.clear();

        for (const std::string& filename :
             pointcloudFilenames)
        {
            PointCloud cloud;

            if (!loadPointCloud(
                    cloud,
                    filename))
            {
                return false;
            }

            scene.pointclouds.push_back(
                std::move(cloud)
            );
        }


        // ----------------------------------------------------
        // Scene colours
        // ----------------------------------------------------

        scene.colours_collection.clear();

        if (j.contains("colours_collection"))
        {
            scene.colours_collection =
                j["colours_collection"]
                .get<
                    std::vector<
                        std::vector<int>
                    >
                >();
        }


        // ----------------------------------------------------
        // Scene state
        // ----------------------------------------------------

        scene.colour_index =
            j.value(
                "colour_index",
                0
            );

        scene.use_scene_colours =
            j.value(
                "use_scene_colours",
                true
            );


        return true;
    }
    catch (const json::exception& e)
    {
        fprintf(
            stderr,
            "SceneObject JSON error: %s\n",
            e.what()
        );

        return false;
    }
}
