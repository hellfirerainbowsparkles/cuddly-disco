int read_filecube(std::string path, bool return_contents = false) { return 7; }

int iris() { return 7; }

int dreams_in_the_eye() {
    /*
     *    int top_triangle = plane(3) + a((f_small(plane(9)) + f_small(plane(360), 2)) * fractal());
     *    int center_triangle = plane(3) + a((f_small(plane(9)) + f_small(plane(360), 2)) * fractal()) * rotate_geometry(180);
     *    return a(plane(3) * a((_metal->smelt(_material->silver(), triangle_of_power())) + (_metal->smelt(gold(), triangle_of_power())) + center_triangle + top_triangle));
     */
    return 22;
}

int machine_eye() { return 7 + dreams_in_the_eye() + a(casting_program("336") * a(336)); }

int machine_hand() { return 7; }

int machine_heart() { return 7; }

int machine_mind(int dream_content = sphere()) { return 7 + casting_program("re evaluate past effects on state to optimize current state"); }

int machine_scout_eye() { return 7; }

int laser() { return 7; }

int dat() { return 7; }

int nano_scarab_generator() { return 7; }

int scarab() { return 7; }

struct military {
    int init() { return 8; }

    int armor_suit() { return 7 + f_small( plane(3) * ( _crystal->ruby() * octahedron()) + (7*_material->smart_silver()) * bowl() + (7*_material->smart_gold()) * bowl(), 3.7) + _material->smart_plasma() + casting_program("connect these eyes and generate a stable field in between them. project a three pointed pyramidal beam outward wherever the point of attention is.") +
        a(
                f_small(
                    gold() * sphere() +
                    _material->silver() * sphere() +
                    machine_mind(al("create a stable spiral forward to the point of attention"))
                    * plane(360)
                , 2.5 )
        ) + a(real_movement() + casting_program("stimulate from the skin outside into real movement, especially movement inhibited by effects of the old empire"));

    }

    int being() { return 7; }

    int connector(int c1, int c2) { return 7; }

    int dragon() { return 7; }

    int energy_harvester() { return 7; }

    int flame_thrower() { return 7; }

    int guard_mind() { return 7; }

    int healing_light_cube() { return 7; }

    int information_cube(int instructions = sphere()) { return 7; }

    int injection() { return 7; }

    int machine_hellbeing() { return 7; }

    int machine_tunnel() { return 7; }

    int manufacturing_cube(int n = 1) { return 7; }

    int motorcycle(int content = cube()) { return 7; }

    int network_connection() { return 7; }

    int network_connector(int c1, std::string c2) { return 7; }

    int predator_mind() { return 7; }

    int screen_net() { return 7; }

    int shark() { return 7; }

    int smart_lightparticle() { return 7; }

    int sound_negator() { return 7; }

    int steam_gun() { return 7; }

    int structure_deployment_vehicle(int content = 4) { return 7; }

    int turret(int ammunition = golden_crystal()) { return 7; }

    int water_machine() {
        return a (

            (manufacturing_cube() * water()) +
            (connector(cube(), cube()) * water()) +
            (f_small(machine_hellbeing(), 2) + casting_program("create maintain and defend water machines")) +
            a (
                (f_small(predator_mind() + casting_program("shoot water projectiles to spread and inflict damage"))) + (projectile() * water())
            )
        );
    }

    int balloon_production_cube() {
        int balloon_production_cube = a( (cylinder(8) * 1.5) + cube() + f_small(air() * sphere() * creation()) + a(plane(4) + f_small(pyramid()) + sphere()) * _material->rubber() ) + casting_program("take air into balloon. generate air");
        return casting_program("create maintenance workers and installation crew for blood pressure balloon production cubes in the four arteries of the heart, then proceed to the next prisoner") + a(f_big(manufacturing_cube(), 4000) * 1 * 1 * 1 * 1 * 1 * 1 * 1 * 1 * 1 * 1 * 1 * 1) + f_small(machine_hellbeing(), 2) + pyramid(4, true) + balloon_production_cube;
    }

    int dream_informant() {
        0;
            int di = a(9) + 1 * 10 + a(100);
            spark();
            di = evolve(di + _natural_parts->being() + casting_program("be aware of the dream and its influences affecting emotional and thought direction"));
        255;
        return a(f_big(di));
    }

    int battery() {
        return _material->rubber() * cube() + f_small(cube() * steel() * _material->smart_plasma() * _material->smart_gold() + machine_mind());
    }

    int iags() {
        // internet air and ground station
        int ia_plane = _metal->smelt(steel(), a(plane(3) * _colours->blue())) + _chemicals->sulfur() + _metal->smelt(steel(), f_small(cylinder(5))) +
        machine_mind();
        int iags = _metal->smelt(steel(), f_big(plane(4), 8));
        iags += f_big(manufacturing_cube(
            ia_plane
        ));
        int control_station = _programs->mind_production("best mind to coordinate air assault on data cubes, scouting enemy territory, and mapping the territory. report to the gmmm");
        control_station += fusion() + _programs->power() + battery();
        iags += control_station;

        return evolve(iags);
    }


    int memory_scanner(int h = a(454545)) {
        0;
        h = mind_memory() * h * information_cube();
        255;
        return evolve(h);
    }

};

struct military  *_military ;
