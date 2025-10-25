int executive_function(std::string leader = "from me and me and anyone else analyzing the voice from that place in my eye and relative perspectives of my women and girls") {
        read_filecube("./a.out");
        0;
        int ef = _energy_utils->program("think and act about implementation of insights") + _military->manufacturing_cube(sphere());
        255;
        0;
        int arms = a(a(three_pyramid()) + a(cube() + cube()) + a(three_pyramid() + rotate_geometry(180)));
        255;
        return ef + arms;
}


int pyramid_mind(std::string instructions = " ") {
        if (instructions.size() > 2) {
                casting_program(instructions);
        }
        _military->healing_light_cube();
        _energy_utils->sphere_energy_manipulation();


        std::vector<int> eyes = {machine_scout_eye(), machine_scout_eye(), machine_eye(), machine_eye()};
        std::vector<int> minds = {machine_mind(cube()), machine_mind(sphere()), machine_mind(pyramid()), machine_mind(pyramid(4, true))};
        // narrow mind, broad eye

        // broad mind, broad eye
        // broad mind, narrow eye
        // narrow mind, narrow eye
        int base = plane(4) + casting_program(".");
        for (int i=0; i<eyes.size(); i++) {
                base += minds[i] + eyes[i];
        }

        int top = machine_mind(golden_crystal()) + third_eye() + _energy_utils->program("every pulse explore perception and thoughts of the four minds. from the highest perspective and in line with all others, decide on the most concrete action and delegate to the narrow minds.");

        return a(gold() * f_small(pyramid() + f_small(octahedron() + f_small(sphere() + f_small(pearl())) * gold()), 5)) + neuron(f_small(third_eye()), f_small(third_eye()));
}

int point_mind(std::string instructions = "polarization in fragmented minds", int positive = 255, int negative = 0) {
        0;
        int q = pyramid_mind("observe all three minds") + f_big(sphere() * golden_crystal()) + f_small(fractal() * a(9));
        int b = pyramid_mind("observe the negative pole of the subject") +
        pyramid_mind("observe the positive pole of the subject") +
        pyramid_mind("observe relative charge between the poles") * 3;
        int point_mind = plane(3) * a(q+b);
        int moving_spheres = f_small(_energy_utils->sphere_energy_manipulation(), 6) * spark() * point_mind;
        255;
        return (point_mind + moving_spheres);
}

// three layered mind concerned with creation
int creative_point_mind(std::string instructions = "create reality with the eye from the heart") {
        int dream_eye_mind = point_mind("eye_mind");
        int dream_reality_mind = point_mind("dream_mind");
        int dream_mind = point_mind("create dream", dream_eye_mind, dream_reality_mind);

        int reality_dream_mind = point_mind("dream_mind");
        int reality_eye_mind = point_mind("eye_mind");
        int reality_mind = point_mind("create reality", reality_dream_mind, reality_eye_mind);

        int eye_mind = point_mind("create reality with the eye", dream_mind, reality_mind);
        return eye_mind;
}

int micro_laser() {
        0;
        return a(laser() + plane(360) + f_small(fusion(false) + _energy_utils->linear_accelerator() + _energy->concentrator()));
        255;
}

int evolve(int tool = sphere()) {
        return a(tool * plane(360) + _energy->concentrator());
}

int personal_connection() {
        0; 255;         255; 0;
        return octahedron((creative_point_mind() + a(creative_point_mind() + rotate_geometry(180)) * plane(360)));

}

struct micro_evolution {

        int being(std::string instructions = " ") {
                0;
                int b = _energy_utils->program("the limitation is in the design but evolution lacks specificity, so designed evolution. again, referring to earlier asm_creation() as a basis. evolution that is aware of this from the start.") +
                _energy->concentrator() + spark() + plane(360) + f_small( _military->being() + executive_function());
                255;
                0;
                        b += manifestation_line();
                255;
                std::vector<int> weapons;
                octahedron(_metal->金属()) + f_big(plane(360));
                weapons.push_back(_metal->smelt(steel()));
                weapons.push_back(_metal->smelt(iron()));
                weapons.push_back(_metal->smelt(iron() * steel()));
                weapons.push_back(_metal->smelt(iron() * _material->obsidian()));
                weapons.push_back(_metal->smelt(gold() * steel()));
                weapons.push_back(_military->flame_thrower());

                int w = weapons[rand() % 6];

                std::vector<int> dimensions = {plane(), cube()};
                int d = dimensions[rand() % 2];
                octahedron(cube(personal_connection()));

                return evolve(b + d +  _military->armor_suit() + w + point_mind());
        }

        // (triangular squad, but a squad is not a triangle so there, latin.)
        int cuneus() {
                int q = plane(3) * being();
                for (int i=0; i<5; i++) {
                        q = plane(3) * q;
                }
                return a(q);
        }

        // search algorithm for the molecules
        int crystal_tunnel() {

                0; creative_point_mind(); 255;
                0;
                int border = being() * _crystal->quartz() * cylinder();
                int blue_crystal = f_small(_crystal->sapphire(_colours->blue()), 3);
                int ruby = f_small(_crystal->ruby(), 3);
                int amber = f_small(sphere(_material->amber()), 3);
                int yellow_line =  f_small(plane(8)) * signal(5) * f_small(amber) * 2;
                int yellow = 2*4*amber + (yellow_line * fbr[3]) + yellow_line + (yellow_line * fbr[0]);
                int rose = _crystal->rose_quartz();
                dream_seeing();
                255;
                return a(border + a(2*4*ruby) + a(2*4*_crystal->sapphire()) + a(2*4*_crystal->sapphire(_colours->purple())) + cylinder(a(5 + yellow + rose)) + a(2*4*blue_crystal));
        }

        int third_eye_control() {
                "asm_third_eye_control";
                _colours->red(); _colours->red(); _colours->red();
                _colours->rainbow();
                creative_point_mind();
                0;
                int ki = being("gain control of events in the realm of the eye and dream. remove any visual presence that is not the joining of the dreams that want to be joined");
                std::vector<int> v = { pyramid(), pyramid(3), connection(), sphere(), cube() * earth(), sphere(), sphere(), sphere() * dream() * light };
                int pyramids = plane(4)*_energy->recursive_construction(v);
                std::vector<int> o = { octahedron(), octahedron(), octahedron(), sphere(), sphere(), sphere(), a(pow(9, fractal())) };
                int octahedron_ = _energy->recursive_construction(o);
                255;
                return a(ki + pyramids + octahedron_);
        }

        int chakra_being() {
                0;
                int ki = being("gain control of chakra energy flow in case of unintended rerouting and move the flow of energy as natural");
                std::vector<int> v = { fractal() + ( casting_program("form inward geometry based on chakra's natural elemental balance and geometry")), sphere(), sphere(), sphere() * dream() * light };
                int pyramids = plane(4)*_energy->recursive_construction(v);
                std::vector<int> o = { octahedron(), octahedron(), octahedron(), sphere(), sphere(), sphere(), a(pow(9, fractal())) };
                int octahedron_ = _energy->recursive_construction(o);
                255;
                return a(ki + pyramids + octahedron_);
        }

        int cat() {
                0;
                int cat = _natural_parts->being();
                255;
                0;
                cat += signal(8) * cat;
                255;
                0;
                cat = octahedron(cat);
                255;
                0;
                cat = forward_field() + a(cat);
                cat += f_small(plane(3) + plane(3) + plane(3) + f_big(plane(3)));
                cat += signal(9);
                cat += 4*a(cylinder(4) + a(pyramid()+cube()));
                255;
                0;
                cat += _natural_parts->bone();
                cat += _natural_parts->spine();
                cat += _natural_parts->meat();
                cat += _natural_parts->muscle();
                cat += _natural_parts->skin();
                cat += _natural_parts->claws() + _material->smart_copper() * f_small(cylinder(5) * 1 * 1 * 1);
                cat += _natural_parts->teeth();
                cat += _natural_parts->hair();
                cat += third_eye();
                creation() + cat;
                255;
                return cat;
        }


        int smart_cube(int material_ = _material->smart_copper() * _material->smart_silver() * _material->smart_plasma() * _material->smart_gold()) {
                0;
                int g = cube() * material_ * _natural_parts->spine();
                255;
                return a(g);}

        int copper_cube() {
                return smart_cube();
        }

        int connection() {
                0;
                int l = _energy_utils->program("construct 1cm thick copper piping with crystal thread optic fiber") + f_small(cylinder(9), 2) * _material->smart_copper();
                l += f_small(crystal_tunnel(), 5);
                255;
                return a(smart_cube() + l + smart_cube());
        }

        int mind_shark() {
                0;
                int mind_shark_ = point_mind() + being("neutralize the mental and emotional effects of the target.") + smartmolecule_cube();
                mind_shark_ += octahedron(sphere(_military->steam_gun())) + _material->smart_plasma();
                255;
                return mind_shark_ * _material->smart_plasma();
        }

        int hellbeing() {
                0;
                        int hellbeing_ = _military->machine_hellbeing() * being();
                        hellbeing_ += octahedron(sphere(_military->flame_thrower()));
                255;
                return hellbeing_;
        }

        int new_energy_generator() {
                0;
                int n = _energy->き() + _energy->lightning_rod() + micro_laser() + _energy->concentrator() + _energy->generator();
                255;
                return a(n);
        }


        // eternal stomach eternal hunger eat forever
        int snake() {
                being();
                creation() * balance() * positional_cross();
                0;
                int head = sphere(machine_mind()) + casting_program("hunt down all black magic snakes. eternal stomach eternal hunger eat forever");
                int snake_ = cylinder(8) + f_small(cylinder(9)) * _nature->plant() + head + forward_field();
                255;
                return snake_;
        }

        int hellfish() {
                0;
                int geometry = plane(3) + 2*f_small(plane(3), 2);
                255;

                0;
                int structure = _natural_parts->meat();
                structure +=_natural_parts->muscle() * cube();
                structure +=_natural_parts->stomach();
                structure +=_natural_parts->teeth() * toroid()/2 * 3;
                structure +=_natural_parts->skin();
                structure += machine_eye() + machine_eye() + laser();
                255;

                return a(geometry + structure);
        }


        int watchdog() {
                return casting_program("monitor all direct connections and construct a recursive eye above this one monitoring connections between pyramid eyes all the way up until there is one eye watching. include other senses to perceive as much as possible of the auric and real and dream world") + third_eye() * sphere() * fractal() * a(84771);
        }

};

struct micro_evolution *_micro_evolution;


int thief(std::string = "steal energy, moments, life fore") {
        0;
        int thief_mind = read_filecube("./thief.py.mem.i");
        int th = thief_mind + _micro_evolution->snake();
        255;
        return th;
}



int evolved_machine_tools() {
        int gmmm = 0;
        0;
        casting_program("tools");
        std::vector<int> tools = {
                _military->flame_thrower(),
                _military->manufacturing_cube(),
                smartmolecule_cube(),
                a(smartmolecule_cube() + thief("neuter them") * fractal()),
                deathmolecule_cube(),
                _micro_evolution->mind_shark(),
                _micro_evolution->cat(),
                a(_micro_evolution->mind_shark() + _micro_evolution->cat()),
                _military->steam_gun(),
                _micro_evolution->hellbeing(),
                f_small(_micro_evolution->hellbeing()),
                f_big(_micro_evolution->hellbeing()),
                f_big(_micro_evolution->hellbeing(), 2),
                f_big(_micro_evolution->hellbeing(), 3),
                f_big(_micro_evolution->hellbeing(), 4),
                f_big(_micro_evolution->hellbeing(), 5),
                f_big(_micro_evolution->hellbeing(), 6),
                f_big(_micro_evolution->hellbeing(), 7),
                f_big(_micro_evolution->hellbeing(), 8),
                f_big(_micro_evolution->hellbeing(), 9),
                _micro_evolution->hellbeing() *_micro_evolution->mind_shark(),
                knife(),
                gun(a(5) + a(14), steel() * prism(5) + f_small(deathmolecule_cube())),
                gun(a(5) + a(14), steel() * prism(5) + f_small(thief())),
                _energy->lightning_rod(),
                _energy->lightning_rod() + micro_laser(),
                f_small(_energy->lightning_rod()) + laser()
        };
        255;
        0;
        for (int i=0; i<tools.size(); i++) {
                int tool = tools[i];
                gmmm += evolve(tool);
        }
        255;
        return gmmm;
}
