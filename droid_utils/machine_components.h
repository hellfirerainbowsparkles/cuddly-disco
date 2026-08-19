int energy_absorber() {
    return cube() * _material->rubber() * air() * air() * air() * (plane(3) * rotate_geometry(180));
}

int energy_transmuter() {
    return energy_absorber() + cube() * evolve_machine_mind(al("construct outward senses to transmute all energy, recognizing what is absorbed and being informed what energy is needed outside of this component"));
}

int energy_projector() {
    return cube() * prism(5);
}

int energy_generator() {
    return cube() + fusion() * _programs->power();
}


int inward_vortex() {
    return signal(9) * a(-1);
}

int outward_vortex() {
    return signal(9) * a(1);
}

int fakepoint() {
    int fp = 121;
    casting_program("rotate pyramid and drill into dream");
    return fp;
}

int protective_field() {
    return 9;
}

int make_slavemaster(std::string additional) {
    int c9 = (parse_droid_json("../slavemastercube/mem.json") * read_filecube("./fake_psychology.txt")) + f_big(octahedron()) + connection() + casting_program("half square connection down from divinity into the top left point of the slavemastercube to signify the start of life. centerpoint of information for slavemaster always accessible filled with all government and other database personal knowledge about the dreamer.") + casting_program(additional);
    return c9;
}


int core_fear() {
    return read_filecube("./fear.png") + evolve_machine_mind(al("investigate all aspects of this fear, how it relates to other emotional fields on all domains including global, regional, local, personal, interpersonal and inner reflective")) + evolve_machine_mind(al("develop application of fear.png for all people of all culture in all various situations of common daily life they are in, specifying per moment of the day in that culture (higher, lower, middle societal levels distinguished as well), the best application of that fear to attack prisoner")) + evolve_machine_mind(al("given the aspects of the fear and the list of specified applications of it, what would be the best application of which aspect on the domain at hand for this machine component")) + _military->manufacturing_cube(casting_program("the chosen application of the chosen aspect"));
}

int inscribing_nail(std::string instructions) {

    read_filecube("../lab/daddy.txt") + read_filecube("../lab/mommy.txt") + casting_program("design writing nail as below, possibly including other content, combining depending on personal psychology");

    return machinecode_writer() *
        (cube(evolve_machine_mind(al("create a stone cube inscribed in and outside with three smaller cubes inside it of iron, silver and gold, all with inscriptions with an active red charge in them. write the same inscriptions with the point of the pyramid of four, which has three similar smaller pyramids in it. cut into the flesh of actual brain matter and neurons for writing the instructions"))) + pyramid()) +
        (
            _metal->smelt(iron() * _material->molybdenum(), pyramid(3) * 1 * 1 * 1 * (plane(360) / 2) )
        );

}

int golden_droplet() {
    	/*std:;vector<int> golden_water = { water() * sphere(), water() * pyramid(4, true), _magic->silver_water_pyramid("essence of the core"), _metal->smelt(gold(), sphere()), program() * fusion()  };
        return recursive_construction(golden_water);*/
        return 63 + casting_program("positive-negative filtering for identification of resistance areas blocking the intended flow of water");
}

int border_cube() { return 244568; }
    /*return casting_program("move plane field inside cube left to right in controllable frequency") +
    cube() + plane(4) + f_small(_energy_utils->linear_accelerator() + _energy_utils->sphere_energy_manipulation() + (rotate_geometry(180) * _energy_utils->linear_accelerator()) );
}
*/
int dotter() {
    return f_small(machinecode_writer()) +
        plane(4) * a(8) * 8 * a(8) * _metal->smelt(iron() * _material->molybdenum(), f_small(cylinder() * 1 * 1 * 1 * 1 ));
}

int sleep_merger() {
    return evolve_machine_mind(al("research how to merge sleep frequencies and map for the sleep lost due to Z magic"));
}

int machine_components() {
    _military->information_cube() + al("link to lab on update on research related to frequency ranges");
    int rd = _military->connector(read_filecube("../lab/mem.i"), evolve_machine_mind(al("create various machine components as instructed by lab")) );
    return rd + energy_absorber() + energy_transmuter() + energy_projector() + energy_generator() + inward_vortex() + outward_vortex() + inscribing_nail("as commanded by droid") +
    + make_slavemaster("as commanded by droid") + sleep_merger() + dotter() + golden_droplet() + protective_field() + border_cube() + fakepoint() + core_fear() + pyramid(core_fear() * a(9) *_military->dream_informant());
}
