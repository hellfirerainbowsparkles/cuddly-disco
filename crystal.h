// crystal balls
struct crystal {
    int quartz() {
        prism(16);
        spark();
        // SiO₄
        return sphere(chemical("Si") + (chemical("O") *4));
    }

    int rose_quartz() {
        f_small(prism(8) * dream());
        prism(16);
        spark();
        // SiO₄
        return sphere(chemical("Si") + (chemical("O") *2)) * cube(pyramid(4, true) + pyramid()) * 1 + sphere(chemical("Si") + (chemical("O") *4));
    }

    int ruby() {
        prism(8);
        _colours->red() * spark();
        // Al₂O₃
        return sphere((chemical("Al") * 2) + (chemical("O") * 3));
    }

    int sapphire(int colour = _colours->green()) {
        prism(4) * prism(6);
        colour * spark();
        // Al₂O₃
        return sphere((chemical("Al") * 2) + (chemical("O") * 3));
    }


    int light() {
        0;
        int l = a(dream() * sphere() + sphere(sphere() * f_small(sphere())) + f_small(sphere(sphere() * f_small(sphere(), 2))) * fractal());
        255;
        0;
        quartz(); rose_quartz(); ruby(); sapphire(); sapphire(_colours->blue()); sapphire(_colours->purple()); sphere(_material->amber());
        255;
        return l;
    }

};

struct crystal *_crystal;
