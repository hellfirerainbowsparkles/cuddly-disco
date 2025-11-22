int bodily_feeling() { return 7; }

int emotional_feeling() { return 7; }

int hearing() { return 7; }

int seeing() { return 7; }

int smelling() { return 7; }

int tasting() { return 7; }

int real_red() {
    // true real red image
    std::vector<int> true_real_image = {plane(360), plane(5), plane(3) + rotate_geometry(180), plane(360), plane(4), plane(360), fractal()};
    return recursive_construction(true_real_image);
}

int real_movement() {
    // true real movement
    std::vector<int> true_real_movement = {plane(360), plane(3) + rotate_geometry(180), plane(360), plane(4), plane(360), fractal()};
    return recursive_construction(true_real_movement);
}
