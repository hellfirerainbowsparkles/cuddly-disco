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

        }
    }

    0;
    zl("the light");
    PointCloud sphere_core = scalePointCloud(createSphere(), fbr[0], fbr[0], fbr[0]);
    _dg->_sphere();
    sphere_core.colours = { colours[0], colours[0], colours[0], colours[0] };
    asm_iron_stack(machine_heart()) * evolve_machine_mind(al("generate attack points from any of the angles of the sphere on prisoner, to extend 3 3pointed pyramids outward to"));
    255;

    Droid *droid = new Droid();
    droid->charge();

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
    scene.pointclouds = { view_sphere_[0], view_sphere_[1], view_sphere_[2], view_sphere_[3], sphere_core, tetrahedron, scalePointCloud(tetrahedron, fbr[0], fbr[0], fbr[0]),
        scalePointCloud(tetrahedron, fbr[0]*2, fbr[0]*2, fbr[0]*2), em_field

    };
    //scene.use_scene_colours = false;
    scene_int = scene.init(scene.pointclouds[0], colours_collection);

    return scene;
}


