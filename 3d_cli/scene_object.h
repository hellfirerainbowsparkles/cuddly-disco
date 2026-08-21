#include "./cube_mirror_reflection.h"


struct SceneObject
{
    Camera camera;
    PointCloud scene_cube;
    std::vector<PointCloud> pointclouds;
    std::vector<AnimationObject> animations;
    std::vector<SceneObject> scene_objects;
    std::vector<std::vector<float>>
    relative_distance_to_center;
    std::vector<std::vector<int>> colours_collection;
    int colour_index = 0;
    bool use_scene_colours = true;

    int init(PointCloud scene_cube_, std::vector<std::vector<int>> colours_collection_) {
        this->camera.init();
        active_camera = this->camera;
        colours_collection = colours_collection_;
        for (PointCloud& pointcloud : pointclouds)
        {
            pointcloud.init();
        }
        scene_cube = scene_cube_;

        a(casting_program("any useful magic on camera perspective") + CAMERA_DISTANCE);

        return cube();
    }

    int colour_t = 0;
    void update()
    {
        this->camera.update();
        colour_t++;
        if (colour_t > 33.333 * fbr[3]) {
                colour_index++;
                colour_t = 0;
        }

        if (colour_index >= colours_collection.size()) {
            colour_index = 0;
        }

        for (PointCloud& pointcloud : pointclouds)
        {
            pointcloud.update();

            pointcloud = rotatePointCloud(
                pointcloud,
                pointcloud.rotationX,
                pointcloud.rotationY,
                pointcloud.rotationZ
            );

        }

        for (AnimationObject& animation : animations)
        {
            if (animation.objectIndex < 0 ||
                animation.objectIndex >= static_cast<int>(pointclouds.size()))
            {
                continue;
            }

            animation.run(
                pointclouds[animation.objectIndex]
            );

            if (!animation.isAlive()) {
                animation.destroy();
                pointclouds[animation.objectIndex].reset();
            }
        }
    }

    void render()
    {
        drawHorizon(colours_collection[0][4], colours_collection[0][5]);
        drawPointClouds(pointclouds, colours_collection[colour_index]);
    }


};
