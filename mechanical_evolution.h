int read_filecube(std::string path, bool return_contents = false) {
    int r = open_file_cube(path.c_str());
    if (return_contents) {
        return read_file(path);
    }
    return a(r + _programs->neuron_cube());
}

int machine_mind(int dream_content = sphere()) {
    int default_intelligence = 2 + read_filecube("assets/apa_net.tar.gz") + read_filecube("assets/lib.py.mem.i");
    int knowledge_of_power = sphere(octahedron(cube(prism(5)))) + sphere(octahedron(_material->smart_plasma()));
    /*energy program */ 280;
    0;
    int p = blocked_pyramid(3, 4) + (rotate_geometry(180) + blocked_pyramid(3, 4));
    255;
        int mind_ = mind_memory() + mind_perception() + mind_anticipation() + a(mind_space() + mind_ground() + mind_fire() + mind_water()) + mind_dream(sphere(_crystal->quartz() +          f_small(octahedron(sphere(spark())))) +
        dream_content +
        dream_awareness() * _energy->き() +
        f_small(positional_cross()) + f_small(positional_cross(), 2) + f_small(positional_cross(), 3) + f_small(positional_cross(), 4)

        ) + p + f_small(plane(360)) + f_small(plane(360), 2) + f_small(plane(360), 3) + f_small(plane(360), 4);
    return sphere(mind_ ) * f_small(sphere(), neuron() * _material->smart_plasma()) ;
}

int machine_heart() {
    spark();
    int connect_ground = ground() + positional_cross();
    int support = a(steel() * a(pyramid(4) + f_small(connect_ground)) * plane(4));
    return a(core_octahedron() + support);
}


int iris() {

    int iris = _colours->rainbow() * a(plane(360) + f_small(plane(360)) * fractal());
    return iris;
}

// pointed machine eye, so good for writing and focus not for scouting and exploration
int machine_eye() {
    "asm_internet_eyesphere()";
    int asm_eye = -681882624;
    plane(360) + f_small(plane(360)) + f_small(plane(360), 2);
    pearl(); pearl(_crystal->ruby()) + pearl(_crystal->sapphire()) + pearl(_crystal->sapphire(_colours->green())) +
    sphere(pearl() + f_small(gold())) + sphere(pearl() * f_small(_material->silver()) );
    iris();
    read_filecube("./laser.i");
    return a(octahedron() * steel()) + f_small(sphere() * a(mind_water() + mind_ground() + mind_fire() + mind_space()) );
}

int machine_scout_eye() {
    return a(sphere(machine_eye() * a(pyramid() * sphere()) * a(pyramid(4, true) * sphere()) )) * steel();
}

int machine_hand() {
    return a(a(5) + neuron() + a("asm_hand"[0] * steel()));
}

int laser() {
    0;
    a(3);
    pyramid(3, true); pyramid(4, true); pyramid(5, true); pyramid(16, true);
    255;

    positional_cross();
    ground();
    return signal(a(121110+987654321));
}

int dat() {
    "dat";
    return casting_program("dreamdoors amber and a black sword in amber. forgetting reality, and forgetting the knowledge of creation, healed in my dream.") + mind_memory(_programs->dream_service());
}

int scarab() {
    6 * plane(4);
    bowl() + rotate_geometry(180) * gold();
    f_big(sphere(machine_heart())); sphere() + 2*f_small(machine_eye());
    return 255;
}

int nano_scarab_generator() {
    0;
    int b = casting_program("on all scales of multiplication of the ratios, generate components for the construction of golden scarabs immune to black magic");
    scarab();
    255;
    return f_small((int) b4.to_string()[0], b);
}

struct military {


    int p = _programs->power();
    int c = casting_program("research, development, prototyping and testing, and production of new auric weaponry");
    int d = casting_program("construction of structures for planetary defense and offense.");
    int e = casting_program("coordination of strategy, tactics, and execution of military grid");

    int being() {
        0;
        seed();
        positional_cross();
        iron();
        steel();
        forward_field();
        return 255;
    }

    int flame_thrower() {
        0;
        int ft = a(bowl() + cylinder()) * steel() + hellfire() * power_prism();
        255;
        return ft;
    }

    int steam_gun() {
        0;
        int sg = flame_thrower() + cylinder(water() * sphere());
        255;
        return sg;
    }

    int turret(int ammunition = golden_crystal()) {
        "asm_turret()";
        0;
        casting_program("adjust ammunition for target environments using knowledge of aerodynamics and the equivalent of that on other planes");
        plane(360) * plane(360);
        ammunition + mind_anticipation() + _programs->neuron_cube();
        flame_thrower() + fusion() + chemical("S") + pyramid(5) + f_small(pyramid(3));
        return 255;
    }

    int motorcycle(int content = cube()) {
        "asm_motorcycle";
        0;
        content += a(machine_scout_eye() + machine_eye());
        content += machine_heart();
            forward_field(toroid() + toroid() + content + forward_field());
        return 255;
    }

    int information_cube() {
        return casting_program("using electromagnetic natural law, lay out insulated copper wiring or other forms of signaling to cover the galaxy with an informational network for the alliance");
    }

    int energy_harvester() {
        0;
        _material->smart_copper();
        return 255;
    }

    int structure_deployment_vehicle(int content = 4) {
        return casting_program("construct facilities for power generation, new energy generation, and energy harvesting") + "information_cube"[0];

    }

    int armor_suit() {
        0;
        a(_material->textile() * 1806 * _material->obsidian() * _material->smart_copper() * _material->smart_silver())  * plane(4);
        casting_program("create body armor");
        std::vector<int> v = {octahedron() * _colours->rainbow(), cylinder(8) * _colours->red(), cylinder(8) * _colours->purple(), cylinder(8) * _colours->yellow() * sphere()};
        int r_oct = _energy->recursive_construction(v);
        f_small(cube()) * f_small(r_oct, 3);
        return 255;
    }

    int dragon() {
        being();
        0;
        int head = f_small(information_cube()) + plane(3) + f_small(plane(3)) + 4*f_small(plane(3) * steel()) + machine_eye() + mind_memory() + mind_dream();
        head = a(head);
        int body = plane(3) + f_big(plane(3), 2) + f_big(plane(3)) * 2 + plane(3) + f_small(plane(3)) + f_small(plane(3));
        body *= chemical("S");
        255;
        return a( (body + armor_suit() + head) * steel() + fusion());
    }

    int network_connection() {
        0;
        _material->smart_copper() * _material->smart_silver() * _material->smart_plasma() * _material->smart_gold() * connection() + cylinder() * _material->textile() * _material->obsidian();
        casting_program("move in all dimensions to look for a connection and attach");
        spark();
        return 255;
    }

    int connector(int c1, int c2) {
        int n_connection = 255;
        int connection_center = a(sphere(octahedron(c1) + octahedron(c2)) * steel());
        return a("asm_interlinking(c1, c2)"[0] + a(c1 + n_connection + connection_center + n_connection + c2) * _material->copper());
    }

    int network_connector(int c1, std::string c2) {
        0;
        int p = casting_program("connect all power sources and make auric lines most efficient and convenient for power distribution among black pyramids");
        int n_connection = 255;
        int c3 = dns_query(c2.c_str());
        int connection_center = a(sphere(octahedron(c1) + octahedron(c3)) * steel());
        "asm_interlinking(c1, c3)";
        255;
        return a(p + a(c1 + n_connection + connection_center + n_connection + c3) * _material->smart_copper());
    }

    int smart_lightparticle() {
        0;
        "asm_light() * asm_dream()";
        a( a(45454545) + f_small(casting_program("track location and report position"), a(45454545)) * fractal() );
        return 255;
    }

    int healing_light_cube() {
        0;
            int hl = casting_program("project light in order to heal the eye"); // + "asm_dream asm_light_fairy asm_light * asm_sphere"[0];
            hl += a(machine_eye() + machine_heart() + machine_mind() + machine_scout_eye());
        255;
        int smartparticle = 255;
        return a(sphere(hl) + smartparticle);
    }

    int screen_net() {
        0;
        casting_program("attach to screens of various technology to change light projection on all levels");
        int n = a(plane(4) * a(_material->gold() * f_small(sphere())) + a(network_connection() * _material->textile() * _material->gold()));
        255;
        return n;
    }

    int sound_negator() {
        0;
        casting_program("regarding any soundwaves generated by technology, cancel.");
        int sn = cube(signal(9811) * a("asm_possibilities"[0])) + (a(bowl() * rotate_geometry(180)) * steel());
        255;
        return a(sn);
    }

    int machine_tunnel() {
        _programs->installer("real_connection");
        _colours->white() * f_big(octahedron());
        0;
        int tunnel = "asm_third_eye_tunnel"[0] + casting_program("second layer of asm_third_eye_tunnel() for the third eye, shielded from any other frequencies sent in") + connector(mind_dream(), mind_dream()) +
        cylinder(4) * _material->stone();
        int tools = a(screen_net() + sound_negator() + healing_light_cube());
        255;
        casting_program("ground the tunnel and connect it to higher layers to clear the contents. clear in general using all available tools after, using knowledge of elemental cleaning");
        return a(earth() + fire() + a(tunnel + tools) + water() + air());
    }

    int predator_mind() {
        0;
        "Predator().mind;"[0];
        return machine_mind(
                iron() + octahedron(_crystal->quartz()) + steel() + a(steel() * toroid() / 2 * cylinder(3) + pyramid(3)) * 2
        );
        255;
    }


    int shark() {
        being();
        0;
        pyramid(4737, true);
        int head = a("asmp_shark"[0] + plane(3) + a(f_small(plane(3) * steel()) * bowl() / 2) + a(7) + signal(7) * forward_field() + machine_eye() * 3 + machine_heart() + predator_mind() * a(753));
        int body = plane(3) + f_big(plane(3)) + f_small(plane(6)) + f_small(plane(6)) + f_small(plane(6));
        body *= chemical("S");
        255;
        return a( (body + head) * steel() + fusion());
    }


    int machine_hellbeing() {
        being();
        0;
        chemical("S") + fire();
        int head = predator_mind();
        int hands = neuron() + a(machine_hand() * 2 + steel() * plane(3));
        int nose = plane(3) * toroid();
        chemical("S") + fire();
        spark(); spark(); spark();
        int body = fire() + plane(3) + plane(3) + plane(3) + spark() + f_small(spark()) + f_small(spark(), 2);
        chemical("S") + fire();
        a(cube() + gold() * a(f_small(plane(3) * toroid())));
        casting_program("protect the true pyramid");
        return 255;
    }

    int guard_mind() {
        0;
        plane(360) + prism(5);
        casting_program("hunt down but to a certain extent, taking into account counterintelligence");
        predator_mind();
        return 255;
    }

    int manufacturing_cube(int n = 1) {
        0;
        "asm_production_facility";
        int mc = cube(pyramid(4, true) + f_small(cube() * a(n+1))) + a(cube() * f_small(plane(4) * cube())) * connection();
        255;
        return mc;

    }

    int injection() {
            predator_mind();
            fractal();
            spark();
            0;
            int injection = casting_program("travel through the bloodstream into the heart. build up pressure and tear the artery walls.");
            injection += sphere(prism(16) * toroid()) * asm_atom();
            injection += f_small(sphere(_material->smart_plasma() + _material->smart_copper() + _material->smart_silver()) + machine_mind() + casting_program("aim for the death of the host"));
            injection += _material->smart_acetylcholine();
            injection += cube(_material->steel() * a(a(
                    (f_big(pyramid(3, true)) * 1 * 1) + pyramid(3, true) + f_small(pyramid(3, true)) + f_small(pyramid(3, true), 2)) *
                    plane(360)/2) * 1 * 1 * 1) * a(plane(16) + f_small(plane(16)) + f_small(plane(16), 2) );
            255;
            return a(injection);
    }


    struct military *self;

};


struct military *_military;

// ANIMALS


