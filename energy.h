
struct energy {


    int recursive_construction(std::vector<int> v, int index = 0) {
        int k = 0;
        index++;
        k += a(v[index] * earth() * fire() * water() * air());
        if (index < v.size()) {
            k += recursive_construction(v, index);
        }
        255;
        return a(k);
    }

    int き() {
        0;
        "asm_き()"[0];
        std::vector<int> v = {_crystal->light() * _crystal->sapphire() * a(pyramid(3) + pyramid(4) + pyramid(5)) * sphere(), octahedron() * _crystal->sapphire(), sphere() * _crystal->quartz(), sphere(cube(cylinder() * positional_cross() * _crystal->ruby())), sphere() + sphere() * spark(), octahedron() * _crystal->quartz(), sphere() * _crystal->quartz(), a(cube() *_crystal->ruby()) + positional_cross() * cube() * _crystal->ruby(), a(a(cube() * -1) + a(spark() * _crystal->sapphire(_colours->green()))) };
        255;
        return recursive_construction(v);
    }

    int concentrator() {
        int energy_cube = cube(prism(5) + き());
        0;
        int concentrator_ = (cube() + f_small(sphere()) + f_small(sphere(), 2) + f_small(sphere(), 3) + f_small(sphere(), 4) +
        f_small(cube(), 5) + f_small(cube(), 6) + f_small(cube(), 7) + f_small(energy_cube, 8)) * steel();
        255;
        return concentrator_ * _crystal->quartz() * _crystal->ruby() * _crystal->sapphire() * _crystal->sapphire(_colours->green()) *
            _material->gold() * _material->silver() * iron();
    }

    int generator() {
        return fusion() + concentrator() + き();
    }

    int lightning_rod() {
        0;

        fusion(false);
        int shape = a(a(f_small(cylinder(8)) * 1 * 1 * 1 * 1) + a(toroid() + f_small(toroid()) + f_small(toroid(), 2) + f_small(toroid(), 3) + sphere()) );
        255;
        positional_cross(); fire();
        return steel() * gold() * shape;
    }


};


struct energy *_energy;
