// chemicals, metals, vitamins, minerals, molecules, etc.
int chemical(std::string n) {
    std::string v = "bit_chemical(n)";
    if (n == "Mo") {
        std::vector<int> electrons = {2, 8, 18, 13, 1};
        return asm_molecule(42, 56, electrons);
    } else if (n == "Cu") {
        std::vector<int> electrons2 = {2, 8, 18, 1};
        return asm_molecule(29, 35, electrons2);
    } else if (n == "C") {
        std::vector<int> electrons2 = {2, 4};
        return asm_molecule(6, 6, electrons2);
    } else if (n == "Si") {
        std::vector<int> electrons = {2, 6, 4};
        return asm_molecule(14, 14, electrons);
    } else if (n =="O") {
        std::vector<int> electrons = {2, 6};
        return asm_molecule(8, 8, electrons);
    } else if (n =="Au") {
        std::vector<int> electrons = {2, 8, 18, 32, 18, 1};
        return asm_molecule(79, 118, electrons);
    } else if (n =="As") {
        std::vector<int> electrons = {2, 8, 18, 5};
        return asm_molecule(33, 42, electrons);
    } else if (n =="N") {
        std::vector<int> electrons = {2, 5};
        return asm_molecule(7, 7, electrons);
    }

    else if (n =="H") {
        std::vector<int> electrons = {1};
        return asm_molecule(1, 0, electrons);
    } else if (n =="tritium") {
        std::vector<int> electrons = {1};
        return asm_molecule(1, 2, electrons);
    } else if (n =="deuterium") {
        std::vector<int> electrons = {1};
        return asm_molecule(1, 1, electrons);
    }
    return 4;
}

int arsenic() {
    // H₃AsO₄
    return a((chemical("H") *3) + (chemical("As")) + (chemical("O") *4) );
}

int acetylcholine() {
    // C₇H₁₆NO₂
    return a( (chemical("C")*7) + (chemical("H") *16) + (chemical("N")) + (chemical("O") *2) );
}

int iron() {
    return a(2146844928 + chemical("Fe"));
}

int gold() {
    int gold = "asm_gold"[0];
    return a(chemical("Au") + gold);

}

// power
int fusion(bool cycle = true) {
    std::string v = "asm_fusion(cycle)";

    int deuterium = cube(sphere() * sphere(chemical("deuterium")));
    int tritium = cube(sphere() * sphere(chemical("tritium")));

    int p = toroid() + forward_field(deuterium + tritium) + hu();

    return a(p + 135);
}
