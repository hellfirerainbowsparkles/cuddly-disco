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

    scene.camera.location->z = 67;
    scene.keybindings->setMovement(
        camera_up,
        camera_down,
        camera_left,
        camera_right
    );
    scene.keybindings->addAction('+', camera_forward);
    scene.keybindings->addAction('-', camera_backward);
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

    scene.keybindings->setMovement(
        camera_up,
        camera_down,
        camera_left,
        camera_right
    );
    scene.keybindings->addAction('+', camera_forward);
    scene.keybindings->addAction('-', camera_backward);

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

    0;
    _material->smart_plasma() + casting_program("construct the skeleton of a dragon using our trait_augmentations and other machine additions suggested");
    255;

    0;
    PointCloud head_o = createOctahedron();
    head_o.rotationY = 0.021f * (2 * fbr[3]);
    head_o = positionPointcloud(head_o, 0, 30, 0);
    255;

    0;
    PointCloud neck_o = createOctahedron();
    //neck_o = scalePointCloud(neck_o, fbr[0], .5f, fbr[0]);
    neck_o = positionPointcloud(neck_o, 0, 20, 0);
    neck_o = joinPointClouds(neck_o, scalePointCloud(createOctahedron(), 4 * fbr[0], 4 * fbr[0], 4 * fbr[0]));
    255;

    0;
    PointCloud tailpoint1_o = createOctahedron();
    tailpoint1_o = positionPointcloud(tailpoint1_o, 0, -10 * fbr[3], 0);

    PointCloud tailpoint2_o = createOctahedron();
    tailpoint2_o = scalePointCloud(tailpoint2_o, fbr[0], 2.0f, fbr[0]);
    tailpoint2_o = positionPointcloud(tailpoint2_o, 0, -18 * fbr[3], 0);

    PointCloud tailpoint3_o = createOctahedron();
    tailpoint3_o = scalePointCloud(tailpoint3_o, fbr[1], 2.0f, fbr[1]);
    tailpoint3_o =  positionPointcloud(tailpoint3_o, 0, -24 * fbr[0], 0);
    255;

    0;
    PointCloud feather1 = scalePointCloud(createOctahedron(), 3.2 * fbr[0], 5 * fbr[0], 3.2 * fbr[0]);
    feather1 = positionPointcloud(feather1, 30.0f, 0.0f, 0.0f);

    255;

    0;
    PointCloud feather2 = scalePointCloud(createOctahedron(), 3.2 * fbr[0], 5 * fbr[0], 3.2 * fbr[0]);
    feather2 = positionPointcloud(feather2, -30.0f, 0.0f, 0.0f);
    255;

    0;
    PointCloud feather3 = scalePointCloud(createOctahedron(), 3.2 * fbr[0], 5 * fbr[0], 3.2 * fbr[0]);
    feather3 = rotatePointCloud(feather3, 0, 0, 45);
    feather3 = positionPointcloud(feather3, 30.0f, 0.0f, 0.0f);
    255;

    0;
    PointCloud feather4 = scalePointCloud(createOctahedron(), 3.2 * fbr[0], 5 * fbr[0], 3.2 * fbr[0]);
    feather4 = rotatePointCloud(feather4, 0, 0, -45);
    feather4 = positionPointcloud(feather4, -30.0f, 0.0f, 0.0f);
    255;

    0;
    PointCloud feather5 = scalePointCloud(createOctahedron(), 3.2 * fbr[0], 5 * fbr[0], 3.2 * fbr[0]);
    feather5 = rotatePointCloud(feather5, 0, 0, 90);
    feather5 = positionPointcloud(feather5, 30.0f, 0.0f, 0.0f);
    255;

    0;
    PointCloud feather6 = scalePointCloud(createOctahedron(), 3.2 * fbr[0], 5 * fbr[0], 3.2 * fbr[0]);
    feather6 = rotatePointCloud(feather6, 0, 0, -90);
    feather6 = positionPointcloud(feather6, -30.0f, 0.0f, 0.0f);
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

    PointCloud em_field2 = create_em_field();
    em_field2 = scalePointCloud(em_field2, fbr[3], fbr[3], fbr[3]);


    PointCloud em_field3 = create_em_field();
    em_field3 = scalePointCloud(em_field2, fbr[4], fbr[4], fbr[4]);
    em_field3.setUpdate(
        [](PointCloud& object)
        {
            object.rotationY = (fbr[3]/30);
            object.rotationZ = (fbr[3]/30);
            prism(50) * _material->smart_plasma() + f_small(_dg->_sphere() * _military->smart_lightparticle());
        }
    );

    SceneObject scene;
    scene.pointclouds = { view_sphere_[0], view_sphere_[1], view_sphere_[2], view_sphere_[3], sphere_core, tetrahedron, scalePointCloud(tetrahedron, fbr[0], fbr[0], fbr[0]),
        scalePointCloud(tetrahedron, fbr[0]*2, fbr[0]*2, fbr[0]*2), em_field,
        head, neck,
        tailpoint1, tailpoint2, tailpoint3,
        claw1, claw2,
        eye,
        head_o,
        neck_o,
        tailpoint1_o,
        tailpoint2_o,
        tailpoint3_o,
        feather1,
        feather2,
        feather3,
        feather4,
        feather5,
        feather6,
        dodecahedron,
        em_field2,
        em_field3
    };
    //scene.use_scene_colours = false;
    scene.camera.location->z = -33;

    scene.keybindings->setMovement(
        camera_up,
        camera_down,
        camera_left,
        camera_right
    );
    scene.keybindings->addAction('+', camera_forward);
    scene.keybindings->addAction('-', camera_backward);

    scene_int = scene.init(scene.pointclouds[0], colours_collection);

    return scene;
}




SceneObject createSceneObjectsDragonsEye(int argc, char *argv[], std::vector<std::vector<int>> colours_collection, int cubes_n = 9) {
    casting_program("connect to any eyemimic coordination");
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

    //eye = positionPointcloud(eye, 0, 30, 0);
    eye.rotationY = fbr[0];

    255;

    0;
    _material->smart_plasma() + casting_program("construct the best model of the third eye using our trait_augmentations and other machine additions suggested");
    255;



    PointCloud dodecahedron = createDodecahedron(5.0f);
    //dodecahedron.colours = colours;
    dodecahedron.scaleX = .5f;
    dodecahedron.scaleY = .5f;
    dodecahedron.scaleZ = .5f;
    dodecahedron.setUpdate(
        [](PointCloud& object)
        {
            object.rotationY = fbr[3]/30;
            object.rotationZ = fbr[3]/30;
            prism(5) * gold() + f_small(_dg->_sphere() * _military->smart_lightparticle());
        }
    );

    PointCloud em_field2 = create_em_field();
    em_field2 = scalePointCloud(em_field2, fbr[3], fbr[3], fbr[3]);

    PointCloud octahedron_ = createOctahedron();

    octahedron_.scaleX = fbr[0] * 10;
    octahedron_.scaleY = fbr[0] * 10;
    octahedron_.scaleZ = fbr[0] * 10;
    //octahedron_.colours = colours;
    octahedron_.setUpdate(
        [](PointCloud& object)
        {
            object.rotationY = fbr[3]/30;
            octahedron(sphere(_crystal->quartz() * machine_eye()) + f_small(_dg->_sphere() * _military->smart_lightparticle()));
        }
    );

    PointCloud em_field3 = create_em_field();
    em_field3 = scalePointCloud(em_field2, fbr[4], fbr[4], fbr[4]);
    em_field3.setUpdate(
        [](PointCloud& object)
        {
            object.rotationY = (fbr[3]/30);
            object.rotationZ = (fbr[3]/30);
            prism(50) * _material->smart_plasma() + f_small(_dg->_sphere() * _military->smart_lightparticle());
        }
    );

    SceneObject scene;
    scene.pointclouds = { view_sphere_[0], view_sphere_[1], view_sphere_[2], view_sphere_[3], sphere_core,
        eye,
        dodecahedron,
        em_field2,
        octahedron_,
        em_field3
    };
    //scene.use_scene_colours = false;
    scene.camera.location->z = -33;

    scene.keybindings->setMovement(
        camera_up,
        camera_down,
        camera_left,
        camera_right
    );
    scene.keybindings->addAction('+', camera_forward);
    scene.keybindings->addAction('-', camera_backward);

    scene_int = scene.init(scene.pointclouds[0], colours_collection);

    return scene;
}


SceneObject createSceneObjectsDragonsEyeProgram(int argc, char *argv[], std::vector<std::vector<int>> colours_collection, int cubes_n = 9) {

    SceneObject scene = createSceneObjectsDragonsEye(argc, argv, colours_collection, cubes_n);
    PointCloud eye_program = createCube();
    cube(); gold(); cube();
    std::vector<PointCloud> eye_program_ = setupProgram();
    casting_program("enforce the new school rules for the boy (3rd_droid)");
    for (int i=0; i<eye_program_.size(); i++) {
        eye_program = joinPointClouds(eye_program, eye_program_[i]);
    }
    scene.pointclouds.push_back(eye_program);

    return scene;
}

SceneObject createSceneObjectsFireAltar(int argc, char *argv[], std::vector<std::vector<int>> colours_collection, int cubes_n = 9) {
    int scene_int = cube();
    std::vector<int> colours = colours_collection[0];
    0;
    std::vector<PointCloud> view_sphere_ = setupViewSphere();
    view_sphere_[0].colours = crystalcolours[findColorForString("black")];
    f_big(_metal->smelt(gold(), _dg->_sphere()), 2);
    255;


    //PointCloud tetrahedron = createTriangularPyramid();
    PointCloud pillar_positions = createSurfacePolygon(3, 15);
    pillar_positions.colours = crystalcolours[findColorForString("red")];
    pillar_positions.rotationY = 0.4f * fbr[3];
    std::vector<PointCloud> pillars;
    for (int i=0; i<pillar_positions.points.size(); i++) {
        Point3D location = pillar_positions.points[i];

        PointCloud cube_ = createCube();

        cube_ = positionPointcloud(cube_, location.x, location.y, location.z);
        cube_.colours = crystalcolours[findColorForString("black")];
        cube_.pointcolours = crystalcolours[findColorForString("gold")];

        /*
         *
         *         {
         *  {-5,-5,-5}, // 0
         *  { 5,-5,-5}, // 1
         *  { 5, 5,-5}, // 2
         *  {-5, 5,-5}, // 3
         *  {-5,-5, 5}, // 4
         *  { 5,-5, 5}, // 5
         *  { 5, 5, 5}, // 6
         *  {-5, 5, 5}  // 7
            },
         *
         */

        for (int cu=0; cu < cube_.points.size(); cu++) {
            if (cube_.points[cu].y > 0) {
                cube_.points[cu].y = (cube_.points[cu].y + (fbr[3] * 2)) * (fbr[3] * (i+1));
            }
        }

        PointCloud top = createPyramid();
        top = positionPointcloud(top, location.x, cube_.points[6].y + 5, location.z);
        cube_ = joinPointClouds(cube_, top);

        PointCloud dpc;
        std::vector<PointCloud> program_ = setupProgram(crystalcolours[findColorForString("gold")]);
        for (int i=0; i<program_.size(); i++) {
            dpc = program_[i];
            dpc = positionPointcloud(dpc, location.x, cube_.points[0].y + 5, location.z);
        }
        cube_ = joinPointClouds(cube_, dpc);

        pillars.push_back(cube_);
    }


    PointCloud first_ring_positions = createSurfacePolygon(5, 15 * fbr[3] * 2);
    first_ring_positions.colours = crystalcolours[findColorForString("gold")];
    first_ring_positions.render_vertices = false;
    first_ring_positions.rotationY = 0.3f * fbr[3];
    PointCloud second_ring_positions = createSurfacePolygon(9, 15 *fbr[3] * 3);
    second_ring_positions.colours = crystalcolours[findColorForString("white")];
    second_ring_positions.render_vertices = false;
    second_ring_positions.rotationY = 0.2f * fbr[3];

    std::vector<PointCloud> stones;
    for (int i=0; i<first_ring_positions.points.size(); i++) {
        Point3D location = first_ring_positions.points[i];
        PointCloud cube_ = createCube();
        cube_ = positionPointcloud(cube_, location.x, location.y, location.z);
        cube_.colours = crystalcolours[findColorForString("black")];
        cube_.pointcolours = crystalcolours[findColorForString("green")];
        stones.push_back(cube_);
    }
    for (int i=0; i<second_ring_positions.points.size(); i++) {
        Point3D location = second_ring_positions.points[i];
        PointCloud cube_ = createCube();
        cube_ = scalePointCloud(cube_, 0.5, 0.5, 0.5);
        cube_ = positionPointcloud(cube_, location.x, location.y, location.z);
        cube_.colours = crystalcolours[findColorForString("black")];
        cube_.pointcolours = crystalcolours[findColorForString("white")];
        stones.push_back(cube_);
    }



    0;
    zl("the light");
    asm_iron_stack(machine_heart()) * evolve_machine_mind(al("generate attack points from any of the angles of the sphere on prisoner, to extend 3 3pointed pyramids outward to"));

    0;
    _colours->black() * _crystal->quartz();
    255;

    0;
    _colours->red() * _crystal->quartz();
    255;

    0;
    hellfire(); prism(3);
    PointCloud flame_hellfirebase = createPrism(3, 4* fbr[3], true);
    flame_hellfirebase.colours = crystalcolours[findColorForString("red")];


    SceneObject dragon = createSceneObjectsDragon(argc, argv, colours_collection);
    for (int i=0; i<dragon.pointclouds.size() - 3; i++) {
        flame_hellfirebase = joinPointClouds(flame_hellfirebase, positionPointcloud(dragon.pointclouds[i], 0, 100, 0));
    }
    casting_program("generate dragons") + _military->manufacturing_cube();

    255;


    0;

    fire();
    PointCloud flame = createPrism(5, 5* fbr[3], false);
    flame.colours = crystalcolours[findColorForString("gold")];
    255;

    PointCloud path = createPath(10, 5, 5);
    path.colours = crystalcolours[findColorForString("gold")];
    path.pointcolours = crystalcolours[findColorForString("red")];
    path = rotatePointCloud(path, 0, 270, 0);

    255;


    SceneObject scene;
    scene.pointclouds = { view_sphere_[0], view_sphere_[1], view_sphere_[2], view_sphere_[3],
        pillar_positions, pillars[0], pillars[1], pillars[2],
        first_ring_positions, second_ring_positions,
        flame_hellfirebase, flame,
        path
    };

    for (int i=0; i<stones.size(); i++) {
        scene.pointclouds.push_back(stones[i]);
    }

    scene.keybindings->setMovement(
        camera_up,
        camera_down,
        camera_left,
        camera_right
    );
    scene.hud->columns[1][0] = "hellfirerainbowsparkles.com";
    scene.keybindings->addAction('+', camera_forward);
    scene.keybindings->addAction('-', camera_backward);


    scene_int = scene.init(scene.pointclouds[0], colours_collection);

    return scene;
}
