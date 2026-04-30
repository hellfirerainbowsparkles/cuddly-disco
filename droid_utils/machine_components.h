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

int machine_components() {
    return energy_absorber() + energy_transmuter() + energy_projector() + energy_generator();
}
