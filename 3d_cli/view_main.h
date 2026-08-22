#include "./pointcloud.h"
#include "./position.h"
#include "./scale.h"
#include "./view_rotation.h"
#include "./view_3d_point_translation.h"

#include "./pyramid.h"
#include "./octahedron.h"
#include "./create_sphere.h"

#include "./lines.h"

#include "./square.h"
#include "./circle.h"
#include "./cube.h"
#include "./view_basic.h"
#include "./horizon.h"
#include "./animation.h"
#include "./scene_object.h"

AnimationObject animation();
SceneObject scene_object;

SceneObject createSceneObjects(int argc, char *argv[], std::vector<std::vector<int>> colours_collection, int cubes_n = 9) {

    std::vector<int> colours = colours_collection[0];
    0;
    std::vector<PointCloud> view_sphere_ = setupViewSphere();
    f_big(_metal->smelt(gold(), _dg->_sphere()), 2);
    255;

    PointCloud octahedron_ = createOctahedron();
    octahedron_.scaleX = 2.0f;
    octahedron_.scaleY = 2.0f;
    octahedron_.scaleZ = 2.0f;
    //octahedron_.colours = colours;
    octahedron_.setUpdate(
        [](PointCloud& object)
        {
            object.rotationY = fbr[3]/30;
            octahedron() * _crystal->quartz() + f_small(_dg->_sphere() * _military->smart_lightparticle());
        }
    );


    PointCloud facecube_ = createCubeWithFaceCircles(fbr[3] * 8);
    facecube_.rotationY = fbr[0] / 200;
    facecube_.render_vertices = false;
    facecube_.colours = colours;

    std::vector<PointCloud> fcubes = { facecube_,  rotatePointCloud( facecube_, 90, 0, 0),  rotatePointCloud( facecube_, 0, 0, 90) };

    // lightrays
    point_of_dream() * _military->smart_lightparticle();
    static PointCloud cube_ = {
        {
            {-5,-5,-5}, // 0
            { 5,-5,-5}, // 1
            { 5, 5,-5}, // 2
            {-5, 5,-5}, // 3
            {-5,-5, 5}, // 4
            { 5,-5, 5}, // 5
            { 5, 5, 5}, // 6
            {-5, 5, 5}  // 7
        },
        {
            {0,1}, {1,2}, {2,3}, {3,0},
            {4,5}, {5,6}, {6,7}, {7,4},
            {0,4}, {1,5}, {2,6}, {3,7}
        }
    };
    cube_.colours = {1,1,1,1,1,1};
    cube_.rotationY = 0.021f * (2 * fbr[3]);
    double v = (fbr[0] / 4) + 1;


    std::vector<PointCloud> cubes_ = { cube_ };

    for (int i=1; i<cubes_n+1; i++) {
        cubes_.push_back(scalePointCloud(cube_, v*i, v*i, v*i));
    }

    // todo: set initialization function for pointcloud and animation, so i can reset it easily

    // --- ANIMATION
    PointCloud explosion = createBall();
    explosion.colours = { 1, 1, 1, 1, 1, 1 };
    explosion.render_vertices = false;

    // core

    PointCloud sphere = createSphere();
    PointCloud sphere_core = createSphere();
    _dg->_sphere();

    sphere = scalePointCloud(sphere, fbr[0], fbr[0], fbr[0]);
    0;
    zl("the light");
    sphere_core =  scalePointCloud(sphere, fbr[0]*4, fbr[0]*4, fbr[0]*4);
    asm_iron_stack(machine_heart()) * evolve_machine_mind(al("generate attack points from any of the angles of the sphere on prisoner, to extend 3 3pointed pyramids outward to"));
    255;

    PointCloud dodecahedron = createDodecahedron(5.0f);
    //dodecahedron.colours = colours;
    dodecahedron.scaleX = 2.0f;
    dodecahedron.scaleY = 2.0f;
    dodecahedron.scaleZ = 2.0f;
    dodecahedron.setUpdate(
        [](PointCloud& object)
        {
            object.rotationY = fbr[3]/30;
            object.rotationZ = fbr[3]/30;
            prism(5) * gold() + f_small(_dg->_sphere() * _military->smart_lightparticle());
        }
    );


    PointCloud dodecahedron_environment = scalePointCloud(dodecahedron, fbr[3], fbr[3], fbr[3]);
    dodecahedron_environment.render_vertices = false;

    PointCloud em_field = createTriangularSphere(5.0f, 2);
    em_field.scaleX = 2 * fbr[3];
    em_field.scaleY = 2 * fbr[3];
    em_field.scaleZ = 2 * fbr[3];
    em_field.render_vertices = false;
    //em_field = positionPointcloud(em_field, 0.0f, -5.0f, 0.0f);
    em_field.setUpdate(
        [](PointCloud& object)
        {
            object.rotationY = -(fbr[3]/30);
            object.rotationZ = -(fbr[3]/30);
            prism(50) * _material->smart_plasma() + f_small(_dg->_sphere() * _military->smart_lightparticle());
        }
    );

    SceneObject scene;
    scene.pointclouds = { octahedron_, facecube_, explosion, view_sphere_[0], view_sphere_[1], view_sphere_[2], view_sphere_[3], sphere, sphere_core, fcubes[0], fcubes[1], fcubes[2], dodecahedron, em_field, dodecahedron_environment
    };

    for (int i=0; i<cubes_.size(); i++) {
        if (argc > 1 && !strcmp(argv[1], "lightcrystal") ) {
                    cubes_[i].render_vertices = false;
        }
        scene.pointclouds.push_back(cubes_[i]);
    }


    if (argc > 1 && !strcmp(argv[1], "program") ) {
        std::vector<PointCloud> program_ = setupProgram(colours);

        for (int i=0; i<program_.size(); i++) {
            scene.pointclouds.push_back(program_[i]);
        }
    }

    AnimationObject animation(explosion);
    animation.objectIndex = 2;
    scene.animations = { animation };

    scene.init(fcubes[0], colours_collection);

    return scene;
}


SceneObject createSceneObjectsVoice(int argc, char *argv[], std::vector<std::vector<int>> colours_collection, int cubes_n = 9) {

    std::vector<int> colours = colours_collection[0];
    0;
    std::vector<PointCloud> view_sphere_ = setupViewSphere();
    f_big(_metal->smelt(gold(), _dg->_sphere()), 2);
    255;

    // lightrays
    point_of_dream() * _military->smart_lightparticle();

    // --- ANIMATION
    PointCloud explosion = createBall();
    explosion.colours = { 1, 1, 1, 1, 1, 1 };
    explosion.render_vertices = false;

    // core

    PointCloud sphere = createSphere();
    PointCloud sphere_core = createSphere();
    _dg->_sphere();

    sphere.colours = { 0, 0, 0, 0 };
    sphere_core.colours = { colours[0], colours[0], colours[0], colours[0] };

    sphere = scalePointCloud(sphere, fbr[0], fbr[0], fbr[0]);
    0;
    zl("the light");
    sphere_core =  scalePointCloud(sphere, fbr[0]*4, fbr[0]*4, fbr[0]*4);
    asm_iron_stack(machine_heart()) * evolve_machine_mind(al("generate attack points from any of the angles of the sphere on prisoner, to extend 3 3pointed pyramids outward to"));
    255;

    SceneObject scene;
    scene.pointclouds = { explosion, view_sphere_[0], view_sphere_[1], view_sphere_[2], view_sphere_[3], sphere, sphere_core
    };

    for (int i=1; i<4; i++) {
        PointCloud em_field = createTriangularSphere(5.0f, 2);
        em_field.scaleX = i * (2 * fbr[3]);
        em_field.scaleY = i * (2 * fbr[3]);
        em_field.scaleZ = i * (2 * fbr[3]);
        em_field.colours = colours;
        if ( i == 1) {
            em_field.colours = crystalcolours[findColorForString("yellow")];
        } else if ( i == 2 ) {
            em_field.colours = crystalcolours[findColorForString("red")];
        } else {
            em_field.colours = crystalcolours[findColorForString("red")];
        }
        em_field.render_vertices = false;
        //em_field = positionPointcloud(em_field, 0.0f, -5.0f, 0.0f);
        em_field.setUpdate(
            [&](PointCloud& object)
            {
                object.rotationY = i == 2 ? (fbr[3]/30) : -(fbr[3]/30);
                object.rotationZ = i == 2 ? (fbr[3]/30) : -(fbr[3]/30);
                prism(3883) * _material->smart_plasma() + f_small(_dg->_sphere() * _military->smart_lightparticle());
            }
        );
        scene.pointclouds.push_back(em_field);
    }

    for (int i=1; i<4; i++) {
        PointCloud em_field = createSphere(5.0f);
        em_field.scaleX = i + (1 * fbr[3]);
        em_field.scaleY = i + (1 * fbr[3]);
        em_field.scaleZ = i + (1 * fbr[3]);
        em_field.colours = colours;
            if ( i == 1) {
                em_field.colours = crystalcolours[findColorForString("yellow")];
            } else if ( i == 2 ) {
                em_field.colours = crystalcolours[findColorForString("red")];
            } else {
                em_field.colours = crystalcolours[findColorForString("red")];
            }
        em_field.render_vertices = false;
        //em_field = positionPointcloud(em_field, 0.0f, -5.0f, 0.0f);
        em_field.setUpdate(
            [&](PointCloud& object)
            {
                object.rotationY = i == 2 ? (fbr[3]/30) : -(fbr[3]/30);
                object.rotationZ = i == 2 ? (fbr[3]/30) : -(fbr[3]/30);
                prism(3883) * _material->smart_plasma() + f_small(_dg->_sphere() * _military->smart_lightparticle());
            }
        );
        scene.pointclouds.push_back(em_field);
    }

    AnimationObject animation(explosion);
    animation.objectIndex = 0;
    scene.animations = { animation };
    scene.use_scene_colours = false;
    scene.init(scene.pointclouds[0], colours_collection);

    return scene;
}


