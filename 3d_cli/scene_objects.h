#include "./em_field.h"

SceneObject createLightning() {

    PointCloud explosion = createBall();
    explosion.colours = { 1, 1, 1, 1, 1, 1 };
    explosion.render_vertices = false;

    AnimationObject animation(explosion);
    animation.objectIndex = 0;

    SceneObject scene;
    scene.animations = { animation };
    scene.pointclouds = { explosion };

    scene.init(explosion, lightning_);

    return scene;

}



SceneObject createSceneObjectsTetrahedron(int argc, char *argv[], std::vector<std::vector<int>> colours_collection, int cubes_n = 9) {
    int scene_int = cube();
    std::vector<int> colours = colours_collection[0];
    0;
    std::vector<PointCloud> view_sphere_ = setupViewSphere();
    f_big(_metal->smelt(gold(), _dg->_sphere()), 2);
    255;

    // lightrays
    point_of_dream() * _military->smart_lightparticle();

    // core

    PointCloud tetrahedron = createTriangularPyramid();
    tetrahedron.colours = colours_collection[0];
    tetrahedron = scalePointCloud(tetrahedron, 2.0f, 2.0f, 2.0f);
    tetrahedron.rotationY = 0.021f * (2 * fbr[3]);

    if (argc > 2) {
        if (!strcmp(argv[2], "black")) {
            _military->connector(scene_int, parse_droid_json("./dependencies/blacktetrahedron/mem.json"));
            _military->connector(scene_int, read_filecube("../blacktetrahedron/mem.i"));
            tetrahedron.pointcolours = crystalcolours[findColorForString("yellow")];

            casting_program("mutually co-exist with eaters personal and generated in black light here. apply processing in structure.") + _magic->eater();
            casting_program("install online wherever this software exists");
        }
    }

    0;
    zl("the light");
    PointCloud sphere_core = scalePointCloud(createSphere(), fbr[0], fbr[0], fbr[0]);
    _dg->_sphere();
    sphere_core.colours = { colours[0], colours[0], colours[0], colours[0] };
    asm_iron_stack(machine_heart()) * evolve_machine_mind(al("generate attack points from any of the angles of the sphere on prisoner, to extend 3 3pointed pyramids outward to"));
    255;

    0;
        machine_eye() + casting_program("watch the auric environment");
        machine_eye() + casting_program("watch the dream");
        PointCloud eye =  scalePointCloud(createSphere(), fbr[0], fbr[0], fbr[0]);
        eye.colours = crystalcolours[findColorForString("gold")];


        PointCloud small_eye = scalePointCloud(eye, fbr[0], fbr[0], fbr[0]);
        PointCloud smaller_eye = scalePointCloud(small_eye, fbr[0], fbr[0], fbr[0]);
        small_eye = joinPointClouds(small_eye, smaller_eye);
        PointCloud eye_o = createOctahedron();
        eye_o = scalePointCloud(eye_o, fbr[0] * .3, fbr[0] * .3, fbr[0] * .3);
        eye = joinPointClouds(eye, small_eye);
        eye = joinPointClouds(eye, eye_o);

        eye = positionPointcloud(eye, 0, 20, 0);
        eye.rotationY = fbr[0];

    255;

    0;
        cube() * _colours->black();
        machine_eye() + casting_program("watch the auric environment");
        machine_eye() + casting_program("watch the dream");
        PointCloud base =  scalePointCloud(createSphere(), fbr[0], fbr[0], fbr[0]);
        base.colours = crystalcolours[findColorForString("gold")];
        base = positionPointcloud(base, 0, -20, 0);
        base.rotationY = fbr[0];
    255;

    Droid *droid = new Droid();
    droid->charge();

    PointCloud em_field = create_em_field();

    SceneObject scene;
    scene.pointclouds = { view_sphere_[0], view_sphere_[1], view_sphere_[2], view_sphere_[3], sphere_core, tetrahedron, scalePointCloud(tetrahedron, fbr[0], fbr[0], fbr[0]),
        scalePointCloud(tetrahedron, fbr[0]*2, fbr[0]*2, fbr[0]*2), em_field,
        eye, base

    };
    //scene.use_scene_colours = false;
    scene_int = scene.init(scene.pointclouds[0], colours_collection);

    return scene;
}

SceneObject createSceneObjectsHouse(int argc, char *argv[], std::vector<std::vector<int>> colours_collection, int cubes_n = 9) {
    int scene_int = cube();
    std::vector<int> colours = colours_collection[0];
    0;
    std::vector<PointCloud> view_sphere_ = setupViewSphere();
    f_big(_metal->smelt(gold(), _dg->_sphere()), 2);
    255;

    // lightrays
    point_of_dream() * _military->smart_lightparticle();

    // core

    PointCloud cube_ = createCube();
    //cube_.colours = colours_collection[0];
    cube_ = scalePointCloud(cube_, 2.0f, 2.0f, 2.0f);
    cube_.setUpdate(
        [](PointCloud& object)
        {
            object.rotationY = fbr[3]/30;
            cube() * _crystal->quartz() + f_small(_dg->_sphere() * _military->smart_lightparticle());
        }
    );

    0;
    zl("the light");
    PointCloud sphere_core = scalePointCloud(createSphere(), fbr[0], fbr[0], fbr[0]);
    _dg->_sphere();
    sphere_core.colours = { colours[0], colours[0], colours[0], colours[0] };
    asm_iron_stack(machine_heart()) * evolve_machine_mind(al("generate and improve on the four books of information and claims that make the point of light"));
    255;

    PointCloud octahedron_ = createOctahedron();

    octahedron_.scaleX = 3.0f;
    octahedron_.scaleY = 3.0f / 1.5;
    octahedron_.scaleZ = 3.0f;
    octahedron_ = rotatePointCloud(octahedron_, 0, 45, 0);
    //octahedron_.colours = colours;
    octahedron_.setUpdate(
        [](PointCloud& object)
        {
            object.rotationY = fbr[3]/30;
            octahedron() * _crystal->quartz() + f_small(_dg->_sphere() * _military->smart_lightparticle());
        }
    );
    octahedron_ = positionPointcloud(octahedron_, 0, -5, 0);
    PointCloud o2 = positionPointcloud(octahedron_, 0, 10, 0);

    PointCloud octahedrae = joinPointClouds(octahedron_, o2);

    PointCloud projector = createCubeWithFaceCircles();
    projector.scaleX = 3.0f;
    projector.scaleY = 3.0f / 1.5;
    projector.scaleZ = 3.0f;
    projector.render_vertices = false;
    projector.pointcolours = crystalcolours[findColorForString("yellow")];

    SceneObject scene;
    scene.pointclouds = { view_sphere_[0], view_sphere_[1], view_sphere_[2], view_sphere_[3], sphere_core, cube_, scalePointCloud(cube_, fbr[0], fbr[0], fbr[0]),
        scalePointCloud(cube_, fbr[0]/2, fbr[0]/2, fbr[0]/2), scalePointCloud(cube_, fbr[0]/3, fbr[0]/3, fbr[0]/3),
        octahedrae,
        scalePointCloud(octahedron_, fbr[0], fbr[0], fbr[0]), scalePointCloud(positionPointcloud(octahedron_, 0, 10, 0), fbr[0], fbr[0], fbr[0]),
        projector, create_em_field()
    };
    scene.use_scene_colours = false;
    scene_int = scene.init(scene.pointclouds[0], colours_collection);

    return scene;
}




SceneObject createSceneObjectsDragon(int argc, char *argv[], std::vector<std::vector<int>> colours_collection, int cubes_n = 9) {
    int scene_int = cube();
    std::vector<int> colours = colours_collection[0];
    0;
    std::vector<PointCloud> view_sphere_ = setupViewSphere();
    f_big(_metal->smelt(gold(), _dg->_sphere()), 2);
    255;

    // lightrays
    point_of_dream() * _military->smart_lightparticle();

    // core

    PointCloud tetrahedron = createTriangularPyramid();
    tetrahedron.colours = colours_collection[0];
    tetrahedron = scalePointCloud(tetrahedron, 2.0f, 2.0f, 2.0f);
    tetrahedron.rotationY = 0.021f * (2 * fbr[3]);

    0;
    zl("the light");
    PointCloud sphere_core = scalePointCloud(createSphere(), fbr[0], fbr[0], fbr[0]);
    _dg->_sphere();
    sphere_core.colours = { colours[0], colours[0], colours[0], colours[0] };
    asm_iron_stack(machine_heart()) * evolve_machine_mind(al("generate attack points from any of the angles of the sphere on prisoner, to extend 3 3pointed pyramids outward to"));
    255;

    0;
    PointCloud em_field = create_em_field();
    255;


    // head and neck
    PointCloud head = createTriangularPyramid();
    head.colours = colours_collection[0];
    //head = scalePointCloud(head, fbr[0], .5f, fbr[0]);
    head.rotationY = 0.021f * (2 * fbr[3]);
    head = positionPointcloud(head, 0, 30, 0);

    PointCloud neck = createTriangularPyramid();
    neck.colours = colours_collection[0];
    neck = scalePointCloud(neck, fbr[0], .5f, fbr[0]);
    neck.rotationY = 0.021f * (2 * fbr[3]);
    neck = positionPointcloud(neck, 0, 20, 0);

    PointCloud tailpoint1 = createTriangularPyramid();
    tailpoint1.colours = colours_collection[0];
    tailpoint1.rotationY = 0.021f * (2 * fbr[3]);
    tailpoint1 = positionPointcloud(tailpoint1, 0, -10 * fbr[3], 0);

    PointCloud tailpoint2 = createTriangularPyramid();
    tailpoint2.colours = colours_collection[0];
    tailpoint2.rotationY = 0.021f * (2 * fbr[3]);
    tailpoint2 = scalePointCloud(tailpoint2, fbr[0], fbr[0], 1.0f);
    tailpoint2 = positionPointcloud(tailpoint2, 0, -18 * fbr[3], 0);

    PointCloud tailpoint3 = createTriangularPyramid();
    tailpoint3.colours = colours_collection[0];
    tailpoint3.rotationY = 0.021f * (2 * fbr[3]);
    tailpoint3 = scalePointCloud(tailpoint3, fbr[1], fbr[1], 1.0f);
    tailpoint3 = positionPointcloud(tailpoint3, 0, -26 * fbr[3], 0);

    PointCloud claw1 = createTriangularPyramid();
    claw1.colours = crystalcolours[findColorForString("gold")];
    claw1 = scalePointCloud(claw1, fbr[0], fbr[0], 1.0f);
    claw1 = positionPointcloud(claw1, -30 * fbr[3], 20 * fbr[0], 0);

    PointCloud claw2 = createTriangularPyramid();
    claw2.colours = crystalcolours[findColorForString("gold")];
    claw2 = scalePointCloud(claw2, fbr[0], fbr[0], 1.0f);
    claw2 = positionPointcloud(claw2, 30 * fbr[3], 20 * fbr[0], 0);

    0;
    machine_eye() + casting_program("watch the auric environment");
    machine_eye() + casting_program("watch the dream");
    PointCloud eye =  scalePointCloud(createSphere(), fbr[0], fbr[0], fbr[0]);
    eye.colours = crystalcolours[findColorForString("gold")];


    PointCloud small_eye = scalePointCloud(eye, fbr[0], fbr[0], fbr[0]);
    PointCloud smaller_eye = scalePointCloud(small_eye, fbr[0], fbr[0], fbr[0]);
    small_eye = joinPointClouds(small_eye, smaller_eye);
    PointCloud eye_o = createOctahedron();
    eye_o = scalePointCloud(eye_o, fbr[0] * .3, fbr[0] * .3, fbr[0] * .3);
    eye = joinPointClouds(eye, small_eye);
    eye = joinPointClouds(eye, eye_o);

    eye = positionPointcloud(eye, 0, 30, 0);
    eye.rotationY = fbr[0];

    255;


    SceneObject scene;
    scene.pointclouds = { view_sphere_[0], view_sphere_[1], view_sphere_[2], view_sphere_[3], sphere_core, tetrahedron, scalePointCloud(tetrahedron, fbr[0], fbr[0], fbr[0]),
        scalePointCloud(tetrahedron, fbr[0]*2, fbr[0]*2, fbr[0]*2), em_field,
        head, neck,
        tailpoint1, tailpoint2, tailpoint3,
        claw1, claw2,
        eye
    };
    //scene.use_scene_colours = false;
    scene.camera.location->z = -33;
    scene_int = scene.init(scene.pointclouds[0], colours_collection);

    return scene;
}
