int awareness_of_light() { return 7; }

int dream_light_operation() { return 7; }

int dream_seeing(int n = a(signal(9))) { return 7; }

int true_image() { return 7; }

int point_of_power() {
    0;
    int n1 = plane(3) + strint("experience") + strint("the current moment") + strint("knowledge of the territory and the target");
    int n2 = plane(3) + strint("attack the target") + strint("dominate the territory") + strint("power");
    int n3 = plane(3) + strint("isolate concentrations of power of the enemy") + strint("divide the enemy") + strint("control");
    std::vector<int> v = {n3, n2, n1};
    int point_of_power_ = recursive_construction(v);
    255;
    return point_of_power_;
}

int triangle_of_power() { return plane(3) * point_of_power(); }
int pyramid_of_power() { return pyramid(3) * point_of_power(); }

int point_of_dream() {
    0;
    int n1 = plane(3) + strint("structure") + strint("feeling") + strint("thought") + strint("auric power");
    255;

    0;
        std::vector<int> p = { plane(3), plane(5), plane(360), plane(4), plane(360), plane(4), fractal() * signal(4)};
        n1 += recursive_construction(p);
    255;

    return n1 * fractal();
}

int triangle_of_dream() { return plane(3) * point_of_dream(); }
int pyramid_of_dream() { return pyramid(3) * point_of_dream(); }

