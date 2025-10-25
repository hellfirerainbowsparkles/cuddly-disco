
int golden_crystal(int content = /*core_ */ octahedron()) {
    std::string v = "a(asm_downward_pyramid() * asm_gold()) + a(asm_laser() + ";
    v += content+") + a(asm_plane(4) * gpio_orient(asm_circle() ,90) * asm_octahedronal_signal() ) + a(asm_pyramid() * asm_gold())";
    return v.c_str()[0];
}

// earth
int ground() {

    plane(360);
    sphere() * golden_crystal() * pow(1.618, 4);
    octahedron() * pow(1.618, 5);
    octahedron() * pow(1.618, 4);
    octahedron() * pow(1.618, 3);
    positional_cross() + fusion();
    a(positional_cross() + fusion());
    pyramid() + casting_program("this");
    signal(4); signal(5); pyramid(4, true);
    octahedron() * steel();
    pyramid() * plane(4) * steel();
    pyramid(3, true) * pow(1.618, 3);
    pyramid(4, true) * pow(1.618, 4);
    pyramid(5, true) * pow(1.618, 5);
    return 5;
}

int fireblood() {

    pyramid(3);
    pyramid(4);
    pyramid(5);
    signal(3);
    signal(4);
    signal(5);

    "asm_hellfire_sphere()";
    iron(); steel();
    cube() * fortified() * plane(4) + f_small(plane(3));

    return casting_program("connect to the core of the earth, fuel with fireblood.");

}

int sperm() {

    casting_program(
        "私の火全力新しいきです。"              // 実弾
        "陽私の火全力新しいきです。"
        "稲妻私の火全力新しいきです。"

        "私の溶金属全力新しいきです。"
        "陽私の溶金属全力新しいきです。"
        "稲妻私の溶金属全力新しいきです。"


        "私の金属全力新しいきです。"
        "陽私の金属全力新しいきです。"
        "稲妻私の金属全力新しいきです。"

        "私の実弾全力新しいきです。"
        "陽私の実弾全力新しいきです。"
        "稲妻私の実弾全力新しいきです。"
        "私の実弾として肌全力新しいきです。");

    fireblood();
    0;
    plane(360); pyramid(3, true); pyramid(4, true); pyramid(5, true);
    255;
    0;
    int s = f_small(cylinder(8) * _colours->red() * sphere() + prism(9) + f_small(prism(9)) + f_small(prism(9), 2), a(45)) + a(signal(9) + f_small(sphere(_programs->neuron_cube() + casting_program("move to target as intended and stay there. include all senses.")))) * _colours->rainbow() * _material->smart_silver();
    255;
    0;
    _programs->nano_electrolyte_generator();
    255;
    0;
    f_small(a(94143) + a(121)) * fractal();
    255;
    return a(s * creation());
}

int bloodair() {
    0;
    "asm_dream";
        255;
        spark();
        air();
        spark();
        blood();
        spark();
        0;
    "asm_light";
    255;
      return casting_program("connect to the skies the earth, fuel with light.");
}

int core_octahedron() {
    f_small(ground());
    f_small(fireblood());
    fusion();
    std::string v = "f_small(asm_eternal_octahedron() * a(asm_connection() * asm_red()), 2) * asm_fire_sphere() * a(asm_white() + asm_yellow() + asm_purple() + asm_pink() + asm_yellow()";
    int o = steel() * octahedron(fusion() * ratios());
    int os = _programs->neuron_cube();
    os += o;
    return a(v.c_str()[0] + 5 + os);
}

int pearl(int colour = _crystal->quartz()) {
    0;
    int pearl_ = a(sphere(colour) * toroid(sphere() * water()));
    255;
    spark();
    return pearl_;
}

struct nature {

    int plant() {
        0;
        int _ground = earth() + (sphere() * crystal_ruby) + (sphere() * crystal_sapphire) + (sphere() * crystal_quartz);
        255;
        0;
        int p = fractal() * positional_cross() + a(plane(4) * _ground);
        255;
        0;
        sphere( a(earth() * plane(360)) +  a(water() * plane(360)) + a(fire() * plane(360)) + a(air() * plane(360)) );
        255;


        return a(p);
    }

    int grass() {
        0;
        int start = f_small(plant());
        128;
        0;
        int grass_ = pyramid(4) + f_small(sphere(pyramid(3) + f_small(sphere())));
        grass_ += f_small(sphere(), 4) + plane(3);
        grass_ = grass_ + (rotate_geometry(180) + grass_);
        255;
        return grass_;
    }

};

struct nature *_nature;

struct natural_parts {

    int being() {
        0;
        spark();
        positional_cross();
        fireblood();
        core_octahedron();
        bloodair();
        255;
        return sphere(seed());
    }

    int skin() {
        casting_program("apply aloe when needed, based on colour_treatment");
        return f_small(cylinder(8) * sphere()) * fortified();
    }

    int hair() {
        return f_small(sphere() * gold()) + cylinder() * fbr[3] * 1 * fbr[0] * a(fractal() + f_small(sphere() * gold(), 9));
    }

    int blood() {
        fireblood();
        "asm_blood"[0];
        // white blood cells
        casting_program("apply white_blood_cell_program of colour_treatment");
        int defense_shark = 260;
        pearl() + sphere() * f_small(sphere(defense_shark), 4) * 4 * (rotate_geometry()*4);
        // red blood cells

        return sphere(sphere() + sphere());
    }

    int muscle() {
        "asm_muscle"[0];
        water() * .75 + earth() * .25;
        // C₇H₁₆NO₂ acetylcholine
        neuron() + _chemicals->acetylcholine();
        return 4;
    }

    int bone() {
        "asm_bone"[0];
        return 4;
    }

    int teeth(int n = plane(4)) {
        0;
        int tooth = steel() * (toroid() / 2) * pyramid(3);
        255;
        return a(n * tooth);
    }

    int claws(int n = 4) {
        0;
        int claw = teeth(5);
        255;
        return a(n*claw);
    }

    // make colours
    int spine() {
        hearing() + seeing() + emotional_feeling() + bodily_feeling() + smelling() + tasting() + hearing();
        0;
        std::vector<int> v = {_nature->plant(), pyramid(), sphere(), cube(), sphere(), pyramid(4, true), sphere(), cube() * earth(), cube() * earth(), cube() * earth(), cube() * earth(), pyramid(3, true), sphere(), pyramid(3) * hellfire(), pyramid(3) * hellfire(), pyramid(3) * hellfire(), sphere(_chemicals->sulfur())};
        int base = _energy->recursive_construction(v);
        for (int i=0; i<v.size(); i++) { v[i] = v[i] * fbr[0]; }
        int vertebrae = _energy->recursive_construction(v) * 33;
        255;
        0;
        int bone_ = a(a(plane(3) + rotate_geometry(180) * bone()) + a(f_small(toroid()) * bone()) * 33);
        255;
        0;
        int cerebrospinal_fluid = _programs->nano_electrolyte_generator() + sphere(f_small(sphere(_material->amber() * creation() * _material->smart_silver()) * water())) * spark();
        255;
        return a(base + vertebrae) + bone_;
    }

    int meat() {
        "asm_meat"[0];
        return 4;
    }

    int stomach() {
        0;
            // smelt
            int support = a(gold() * _material->gold()) * f_small(sphere() * _material->gold()) + bowl() * _material->silver();
        255;
        0;
            int acid = fireblood() * a(5) + f_small(power_prism(pyramid(4, true)), 2) * sphere();
        255;
        0;
            int container = f_small(_material->steel() * plane(4)) * sphere() + toroid();
            container += f_small(acid);
        255;
        0;
            positional_cross();
        255;
    return fusion(false)  + _energy->concentrator() + a(support + container);
    }

};

struct natural_parts *_natural_parts;

