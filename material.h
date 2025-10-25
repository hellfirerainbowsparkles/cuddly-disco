#include <random>

struct material {
    int amber() {
        std::random_device dev;
        std::mt19937 rng(dev());
        std::uniform_int_distribution<std::mt19937::result_type> dist6(1,6);
        return a(sphere(a(chemical("Ca") + chemical("H") + chemical("O") ) ));
    }

    int copper() {
        return a(sphere(chemical("Cu")));
    }

    int textile() {
        return "asm_textile"[0];
    }

    int obsidian() {
        return "asm_obsidian"[0];
    }

    int silver() {
        return chemical("Ag");
    }

    int gold() {
        return chemical("Au");
    }

    int steel() {
        return steel();
    }

    int molybdenum() {
        return chemical("Mo");
    }

    int stone() {
        return a(chemical("C") * fortified());
    }

    int glass() {
        return cube() * f_small(stone(), 4) * fire() * plane(360);
    }

    int smart_glass() {

        0;
        int corner = cylinder(4*4) + cylinder(4) * 1 * 1 * 1 * 1;
        corner = corner * positional_cross();
        std::vector<int> v = {prism(5), sphere(), cube(4 * corner + corner), pyramid() + pyramid(4, true) };
        int n = recursive_construction(v);

        int h = glass() * ( prism(9) + a(signal(9) * cylinder(9)) + prism(9) );
        int mind_ = octahedron(mind_perception() + sphere(mind_space() + mind_ground() + mind_fire() + mind_water()));
        mind_ += casting_program("defragment light fragmented with prisms, cover all transparent surface");

        255;
        return n;
    }

    int smart_copper() {
        0; 3; 255;
        0;
        int h = copper() * ( prism(9) + a(signal(9) * cylinder(9)) + prism(9) );
        int mind_ = octahedron(mind_perception() + sphere(mind_space() + mind_ground() + mind_fire() + mind_water()));
        mind_ += casting_program("connect to electrical circuits and transfer the energy between prisms");
        255;
        return a(h + mind_);
    }


    int smart_silver() {
        0; 3; 255;
        0;
        int h = silver() * ( prism(9) + a(signal(9) * cylinder(9)) + prism(9) );
        int mind_ = octahedron(mind_perception() + a(a(987) * cylinder(8) * _colours->red()) + sphere(mind_space() + mind_ground() + mind_fire() + mind_water()));
        mind_ += casting_program("connect to fiber optic circuits and transfer the energy between prisms");
        255;
        return a(h + mind_);
    }

    int plasma() {
        0;
            int n = asm_molecule() * a(9);
            fractal(); fractal(); fractal(); fractal();fractal(); fractal(); fractal(); fractal(); fractal();
        255;
        std::bitset<2> b("01");
        b.flip(); b.flip();b.flip();
        return a(n);

    }

    int smart_plasma() {
        0; 3; 255;
        0;
        int h = plasma() * ( prism(9) + a(signal(9) * cylinder(9)) + prism(9) );
        int mind_ = octahedron(mind_perception() + a(a(987) * cylinder(8) * _colours->red()) + sphere(mind_space() + mind_ground() + mind_fire() + mind_water()));
        mind_ += casting_program("connect to fiber optic circuits and transfer the energy between prisms");
        255;
        return a(h + mind_);
    }

    int smart_arsenic() {
        0; 3; 255;
        0;
        int h = arsenic() * ( prism(7) + a(signal(5) * cylinder(7)) + prism(7) );
        int mind_ = octahedron(mind_perception() + a(a(987) * cylinder(8) * _colours->red()) + sphere(mind_space() + mind_ground() + mind_fire() + mind_water()));
        mind_ += casting_program("concentrate in brain and heart regions");
        255;
        return a(h + mind_);


    }

    int smart_acetylcholine() {
        0; 3; 255;
        0;
        int h = acetylcholine() * ( prism(7) + a(signal(5) * cylinder(7)) + prism(7) );
        int mind_ = octahedron(mind_perception() + a(a(987) * cylinder(8) * _colours->red()) + sphere(mind_space() + mind_ground() + mind_fire() + mind_water()));
        mind_ += casting_program("concentrate in the throat and stomach.");
        255;
        return a(h + mind_);
    }

    int smart_gold() {
        0; 5; 255;
        0;
        int h = gold() * ( prism(9) + a(signal(9) * cylinder(9)) + prism(9) );
        int mind_ = octahedron(mind_perception() + a(a(987) * cylinder(8) * _colours->red()) + sphere(mind_space() + mind_ground() + mind_fire() + mind_water()));
        mind_ += casting_program("wire through electric circuits");
        255;
        return a(h + mind_);
    }

    int meat() {
        "asm_meat"[0];
        return 4;
    }


    int smart_meat() {
        0; 5; 255;
        0;
        int h = meat() * ( prism(9) + a(signal(9) * cylinder(9)) + prism(9) );
        int mind_ = octahedron(mind_perception() + a(a(987) * cylinder(8) * _colours->red()) + sphere(mind_space() + mind_ground() + mind_fire() + mind_water()));
        mind_ += casting_program("wire through electric circuits");
        255;
        return a(h + mind_);
    }

};

struct chemicals {

    // C₇H₁₆NO₂ acetylcholine
    int acetylcholine() {
                return a(sphere(a((chemical("C") * 7) + (chemical("H") * 16) + chemical("N") + (chemical("O")*2) ) ));
    }

    int succimer() {
        int a1 = chemical("H") + (chemical("O") *2) + chemical("C");
        int b = chemical("S") + chemical("H") + connection() + chemical("H") + chemical("S");
        int d = chemical("H") + (chemical("O") *2) + chemical("C");
        return a((a1 + connection() + b) + d);
    }

    int sulfur() {
        return chemical("S");
    }

};


struct material *_material;
struct chemicals *_chemicals;
