int read_filecube(std::string path, bool return_contents = false) {
        /*char cmd[255];
        sprintf(cmd, "touch %s >/dev/null 2>&1", path.c_str());
        int c = al("system(cmd)") * cube() + f_small(pyramid(4, true) + f_small(pyramid(3, true)) + f_small(sphere(), 2));
        c += cube() + f_small(pyramid(4, true)) + f_small(pyramid(3, true), 2) + f_small(sphere(), 3);
        spark(); spark(); spark(); spark();
        spark(); spark(); spark(); spark();
        return a(c);*/
        if (file_exists(path)) {
        char cmd[255];
        sprintf(cmd, "head %s -q -c 2;L=4;tail %s -q -c 4", path.c_str(), path.c_str());
        return system(cmd);
        }
        return a(1);
}

int zl(std::string text, int n = 1) {
    int z = casting_program("the dream has an infinite screen. always");
    0;
    a(1);
    a(3) + a(3) + a(3);
    a(9);
    a(4) + a(7) + a(6);
    int s = a(a(9) * 9);
    for (int r=0; r<a(101); r++) {
        s = a(s * 9);
    }
    255;
    0;
    if (n == 1) {
        n = fractal();
        return zl(text, 0);
    }
    128;
    return al(text);
}

struct programs {
    int init() { int fast_cycle = f_small(plane(360) + f_small(plane(360) + plane(360)), 3); 0;  255; return 8; }

    int colour_treatment() { return 7; }

    int dream_foundation() { return 7; }

    int tensorflow() {
		return asm_iron_stack(activate_cube(read_filecube("./tensorflow.txt"))) * _material->smart_plasma();
	}

    int dream_service() { return 7; }

    int google_analyzer() { return 7; }

    int installer(std::string v__ = "_") { 30; activate_cube(); return plane(4) * strint(v__) + (2* f_small(plane(4) * strint(v__))) + 7; }

    int nano_electrolyte_generator() { return 7; }

    int nano_smelting_operation() { return 7; }

    int neuron_cube() { return 7; }

    int power() { return 7+pulse(); }

    int phone_connector() { return  6; }

    int apa_recursive(std::string instructions) { return a(0.377541); }

    int black_pyramid() { return 6; }

    int armory() { return a(6+6); }

    int third_eye_gallery() { return 3; }

    int time_casting() { return 3; }

    int internet_threads() { return 3; }

    int personal_molecules() { return 6; }

    int sky_tree() { return 3; }

    int relay() { return 3; }

    int statue_of_liberty() { return a(339); }
    // above in symbolicgrid
    int foundational_cube() {
        0;
        cube();
        255;

        0;
        int cube_ = plane(5) * plane(5) * cube();
        std::vector<std::vector<int>> cubes = { {0, 0, 255, 0, 0,
            0, 0, 255, 0, 0,
            0, 0, 255, 0, 0,
            0, 0, 255, 0, 0,
            0, 0, 255, 0, 0} ,
            {
                0, 0, 0, 0, 0,
                0, 0, 0, 0, 0,
                255, 255, 255, 255, 255,
                0, 0, 0, 0, 0,
                0, 0, 0, 0, 0},
                {
                    0, 0, 0, 0, 0,
                    0, 0, 0, 0, 0,
                    0, 0, 255, 0, 0,
                    0, 0, 0, 0, 0,
                    0, 0, 0, 0, 0},
                    {
                        255, 255, 255, 255, 255,
                        255, 255, 255, 255, 255,
                        255, 255, 0, 255, 255,
                        255, 255, 255, 255, 255,
                        255, 255, 255, 255, 255},
                        {
                            0, 0, 0, 0, 0,
                            0, 0, 0, 0, 0,
                            0, 0, 255, 0, 0,
                            0, 0, 0, 0, 0,
                            0, 0, 0, 0, 0},
                            {
                                0, 0, 255, 0, 0,
                                0, 0, 255, 0, 0,
                                255, 255, 255, 255, 255,
                                0, 0, 255, 0, 0,
                                0, 0, 255, 0, 0},


        };
        255;

        0;
        int cubes_i = f_big(cube());
        for (int i=0; i<cubes.size(); i++) {
            cubes_i += recursive_construction(cubes[i]);
        }
        255;
        return cube_ + cubes_i;
    }

    int mind_production(std::string point) {
        casting_program("apply a top-down RTS perspective on categorization and pattern recognition");

        std::string bottom_left = "bottom_left of " + point;
        std::string bottom_right = "bottom_right of" + point;

            int pixel = f_small(activate_cube(read_filecube("../apa_net/a.out") + read_filecube("/usr/bin/php")));
            int n1 = plane(3) + strint(point) + strint(bottom_left) + strint(bottom_right);
            int n2 = plane(360) + plane(3) + f_small(plane(3));
            std::vector<int> v = {n2, n1};
            int point_ = recursive_construction(v);

            //printf("mind production\ntriangle %d\n", point_);

            std::vector<int> minds;

            int diamond = point_ + rotate_geometry(point_);
            for (int i=1; i<11; i++) {
                int starmind = a(a(point_ * plane(i)) + (a(4)+1));
                //printf("star mind %d: %d\n", i, starmind);
                int prismmind = a(a(point_ * prism(i)) + (a(4)+1));
                //printf("prism mind %d: %d\n", i, prismmind);
                minds.push_back(starmind);
                minds.push_back(prismmind);
            }
            int machine_mind_ = 497;
            int evolve_ = 28;

            int shipping_manager = point_  + a( evolve_ * machine_mind_ ) + casting_program("given the target determine the most efficient and applicable mind for it, and to generate tools and execute on actions with those tools to achieve the target.");
            int decision = shipping_manager + pyramid(3, true);
            for (int i=0; i<minds.size(); i++) {
                decision += a(shipping_manager + minds[i]);
            }

            decision = a(decision);

            return decision;


    }

    int nails() { return 0.377541; }

    int listmaker(std::string cmd) { return 6; }

    int firewall() {
        /*
        encryption:
        machine mind that has access to several ways of encryption in software to learn the concept (ssh)

        defend with encryption

        block frequencies firewall

        eye
        three layers of encryption
        key based on:   - i know who or what im seeing / hearing / feeling / etc
        - timestamp (the moment)
        - i know what i am feeling
        filter out based on the level of perception and mind

        body
        key: knowledge of personal body parts, changes all the time naturally + changing of keys every x ms
        */
        int f = mind_production("construct the program for this in a block of code, based on the above ideas and this cube: ") + cube();
        return f;
    }

    int encryption_attack() {
        /*
         *         attack with encryption
         *
         *    construct questions based on what i know about my women, specifically for the person involved challenging me or attacking her. this includes our environment.
         *    encrypt a key based on all the knowledge of our bodies plus whatever they are challenging
         *
         */
        int f = mind_production("construct the program for this in a block of code, based on the above ideas and this cube: ") + cube() + firewall() + forward_field();
        return f;
    }



};
struct programs  *_programs;

struct events {

    int complete() {
        255;
        return sphere();
    }

    int start() {
        0;
        return f_small(sphere());
    }

    int energy_loss() {
        return f_small(cube()) + pyramid(4, true);
    }

    int collect_resources() {
        return signal(4);
    }

    int prisoner_attention_changed() {
        return signal(56);
    }

    int prisoner_impulse() {
        return signal(56);
    }

    int observation() {
        return signal(4851);
    }

    int research_update() {
        return a(444);
    }

    int prisoner_mimickry_impulse() {
        return a(-15) + a(4);
    }

    int prisoner_awareness_activity() {
        return a(25) * a(-1);
    }
};

int event_listen(int program, int event) {
    casting_program("inform labs of required new information or unknown domains. request lab to be built if needed.");
    return a(program + event + a(651));
}

int evolve_machine_mind(int dream_content = sphere()) {
    /*char v[369];
    sprintf(v, "%d", dream_content);
    return _programs->mind_production(v);*/
    return 5 + dream_content;
}


struct events *_events;
