
struct colours {
    int black() {
        prism(-1);
        return a(-1);
    }

    int blue() {
        prism(4);
        return a(4);
    }

    int red() {
        prism(8);
        return a(8);
    }

    int purple() {
        prism(7);
        return a(761);
    }


    int green() {
        sphere(); cube();
        return a(70);
    }

    int yellow() {
        cube(); cube(); prism(5); f_big(sphere());
        return a(5020);
    }

    int white() {
        sphere();
        return a(100);
    }

    int rainbow() {
        int r = pow(sphere() * sphere() * f_small(sphere(), octahedron()), 2);
        return a(r);
    }

    int orange() {
        return yellow() * red();
    }
};

struct colours *_colours;
