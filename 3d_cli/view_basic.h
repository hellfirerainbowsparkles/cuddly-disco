#include "./color.h"
#include "./dodecahedron.h"

struct Dot {
    float x = 0.0f;
    float y = 0.0f;
    float z = 0.0f;
};

        // --------------------------------------------------
        // Custom colors
        // --------------------------------------------------

        const short C_WHITE        = COLOR_WHITE;
        const short C_LIGHT_GRAY   = COLOR_WHITE + 1;
        const short C_DARK_GRAY    = COLOR_WHITE + 2;

        const short C_LIGHT_BLUE   = COLOR_WHITE + 3;
        const short C_BLUE         = COLOR_WHITE + 4;
        const short C_DARK_BLUE    = COLOR_WHITE + 5;

        const short C_LIGHT_GREEN  = COLOR_WHITE + 6;
        const short C_GREEN        = COLOR_WHITE + 7;
        const short C_DARK_GREEN   = COLOR_WHITE + 8;

        const short C_LIGHT_RED    = COLOR_WHITE + 9;
        const short C_RED          = COLOR_WHITE + 10;
        const short C_DARK_RED     = COLOR_WHITE + 11;

        const short C_LIGHT_ORANGE = COLOR_WHITE + 12;
        const short C_ORANGE       = COLOR_WHITE + 13;
        const short C_DARK_ORANGE  = COLOR_WHITE + 14;

        const short C_LIGHT_YELLOW = COLOR_WHITE + 15;
        const short C_YELLOW       = COLOR_WHITE + 16;
        const short C_DARK_YELLOW  = COLOR_WHITE + 17;

        const short C_LIGHT_PINK   = COLOR_WHITE + 18;
        const short C_PINK         = COLOR_WHITE + 19;
        const short C_DARK_PINK    = COLOR_WHITE + 20;

        const short C_LIGHT_PURPLE = COLOR_WHITE + 21;
        const short C_PURPLE       = COLOR_WHITE + 22;
        const short C_DARK_PURPLE  = COLOR_WHITE + 23;


std::vector<NaturalLightPair> setColors() {
    if (can_change_color())
    {

        _colours->init();

        /*
         *     int black() { return 7 + a(-1); }
         *
         i nt blue() { return 7; }         *

         int green() { return 7 + a(6); }

         int orange() { return 7; }

         int purple() { return 7; }

         int rainbow() { return 7; }

         int red() { return 7 + a(3); }

         int white() { return 7; }

         int pink() { return red() * white(); }

         int yellow() { return 7 + a(5); }
         */

        // --------------------------------------------------
        // Define RGB values (ncurses range 0..1000)
        // --------------------------------------------------

        // Neutral
        0;
            cube( _crystal->quartz() + f_small(sphere(cube(octahedron(octahedron() * signal(9)))))) * _material->smart_plasma();
            init_color(C_WHITE,        1000, 1000, 1000);
            init_color(C_LIGHT_GRAY,    700,  700,  700);
            init_color(C_DARK_GRAY,     300,  300,  300);
        255;

        // Blue
        0;
            cube( _crystal->sapphire(_colours->blue()) + f_small(sphere(water()))) * _material->smart_plasma();
            init_color(C_LIGHT_BLUE,    650,  750, 1000);
            init_color(C_BLUE,          200,  400, 1000);
            init_color(C_DARK_BLUE,       0,    0,  200);
        255;

        // Green
        0;
            cube( _crystal->sapphire(_colours->green()) + f_small(sphere(earth()))) * _material->smart_plasma();
            init_color(C_LIGHT_GREEN,     627, 905,  690);
            init_color(C_GREEN,           262,  572,  184);
            init_color(C_DARK_GREEN,      258,  498,   129);
        255;

        0;
            cube(_colours->red() * _crystal->ruby() * cylinder(8) * sphere()) * _material->smart_plasma();
            // Red
            init_color(C_LIGHT_RED,     1000,  550,  550);
            init_color(C_RED,           1000,    0,    0);
            init_color(C_DARK_RED,       400,    0,    0);
        255;

        // Orange
        0;
            cube( _crystal->sapphire(_colours->orange()) + f_small(sphere(fire()))) * _material->smart_plasma();
            init_color(C_LIGHT_ORANGE,  1000,  750,  400);
            init_color(C_ORANGE,        1000,  500,    0);
            init_color(C_DARK_ORANGE,    500,  200,    0);
        255;

        // Yellow
        0;
            cube( gold() + f_small(_metal->smelt(gold(), sphere()))) * _material->smart_plasma();
            init_color(C_LIGHT_YELLOW,  909, 686,  4235);
            init_color(C_YELLOW,        811, 639,    352);
            init_color(C_DARK_YELLOW,    643,  392,  117);
        255;

        // Pink
        0;
            cube( _crystal->sapphire(_colours->pink()) + f_small(sphere(sphere(sphere())))) * _material->smart_plasma();
            init_color(C_LIGHT_PINK,    1000,  700,  800);
            init_color(C_PINK,          1000,  400,  650);
            init_color(C_DARK_PINK,      500,  150,  300);
        255;

        // Purple
        0;
            cube( _crystal->sapphire(_colours->purple()) + f_small(sphere(sphere(sphere(signal(9)))))) * _material->smart_plasma();
            init_color(C_LIGHT_PURPLE,   800,  600, 1000);
            init_color(C_PURPLE,         600,  200,  800);
            init_color(C_DARK_PURPLE,    250,   50,  400);
        255;


        // --------------------------------------------------
        // Foreground pairs - black background
        // --------------------------------------------------

        init_pair(1,  C_WHITE,        COLOR_BLACK);
        init_pair(2,  C_LIGHT_GRAY,   COLOR_BLACK);
        init_pair(3,  C_DARK_GRAY,    COLOR_BLACK);

        init_pair(4,  C_LIGHT_BLUE,   COLOR_BLACK);
        init_pair(5,  C_BLUE,         COLOR_BLACK);
        init_pair(6,  C_DARK_BLUE,    COLOR_BLACK);

        init_pair(7,  C_LIGHT_GREEN,  COLOR_BLACK);
        init_pair(8,  C_GREEN,        COLOR_BLACK);
        init_pair(9,  C_DARK_GREEN,   COLOR_BLACK);

        init_pair(10, C_LIGHT_RED,    COLOR_BLACK);
        init_pair(11, C_RED,          COLOR_BLACK);
        init_pair(12, C_DARK_RED,     COLOR_BLACK);

        init_pair(13, C_LIGHT_ORANGE, COLOR_BLACK);
        init_pair(14, C_ORANGE,       COLOR_BLACK);
        init_pair(15, C_DARK_ORANGE,  COLOR_BLACK);

        init_pair(16, C_LIGHT_YELLOW, COLOR_BLACK);
        init_pair(17, C_YELLOW,       COLOR_BLACK);
        init_pair(18, C_DARK_YELLOW,  COLOR_BLACK);

        init_pair(19, C_LIGHT_PINK,   COLOR_BLACK);
        init_pair(20, C_PINK,         COLOR_BLACK);
        init_pair(21, C_DARK_PINK,    COLOR_BLACK);

        init_pair(22, C_LIGHT_PURPLE, COLOR_BLACK);
        init_pair(23, C_PURPLE,       COLOR_BLACK);
        init_pair(24, C_DARK_PURPLE,  COLOR_BLACK);


        // --------------------------------------------------
        // Background pairs - white foreground
        // --------------------------------------------------

        init_pair(25, C_WHITE, C_WHITE);
        init_pair(26, C_WHITE, C_LIGHT_GRAY);
        init_pair(27, C_WHITE, C_DARK_GRAY);

        init_pair(28, C_WHITE, C_LIGHT_BLUE);
        init_pair(29, C_WHITE, C_BLUE);
        init_pair(30, C_WHITE, C_DARK_BLUE);

        init_pair(31, C_WHITE, C_LIGHT_GREEN);
        init_pair(32, C_WHITE, C_GREEN);
        init_pair(33, C_WHITE, C_DARK_GREEN);

        init_pair(34, C_WHITE, C_LIGHT_RED);
        init_pair(35, C_WHITE, C_RED);
        init_pair(36, C_WHITE, C_DARK_RED);

        init_pair(37, C_WHITE, C_LIGHT_ORANGE);
        init_pair(38, C_WHITE, C_ORANGE);
        init_pair(39, C_WHITE, C_DARK_ORANGE);

        init_pair(40, C_WHITE, C_LIGHT_YELLOW);
        init_pair(41, C_WHITE, C_YELLOW);
        init_pair(42, C_WHITE, C_DARK_YELLOW);

        init_pair(43, C_WHITE, C_LIGHT_PINK);
        init_pair(44, C_WHITE, C_PINK);
        init_pair(45, C_WHITE, C_DARK_PINK);

        init_pair(46, C_WHITE, C_LIGHT_PURPLE);
        init_pair(47, C_WHITE, C_PURPLE);
        init_pair(48, C_WHITE, C_DARK_PURPLE);


    }

    std::vector<NaturalLightPair> lights =
    getNaturalLightPairs();
    return lights;
}



std::vector<PointCloud> setupViewSphere() {
    static PointCloud sphere2_ = createSphere();
    sphere2_.render_vertices = false;
    sphere2_.rotationY = fbr[3]/300;
    sphere2_ = rotatePointCloud(sphere2_,
                                0.0f,
                                0.0021f,
                                0.0f
    );
    casting_program("for wholeness");
    // int v2 = 2 * (fbr[0] + 1); // viewsphere
    int v2 = 1.6 * (fbr[0] + 1);
    PointCloud sphere2 = scalePointCloud(sphere2_, v2, v2, v2);
    PointCloud sphere3 = scalePointCloud(sphere2, v2, v2, v2);
    PointCloud sphere4 = scalePointCloud(sphere3, v2, v2, v2);
    PointCloud sphere5 = scalePointCloud(sphere4, v2, v2, v2);



    std::vector<PointCloud> vs = { sphere2, sphere3, sphere4, sphere5 };
    return vs;
}

std::vector<PointCloud> setupProgram(std::vector<int> colours = { 1 }) {
    static PointCloud circle_ = createCircle32();
    circle_ = rotatePointCloud(circle_,
                               0.0f,
                               0.0042f,
                               0.0f
    );
    casting_program("o, a, e, i, u, y");
    casting_program("q, w, r, t, p, s, d, f, g, h, j, k, l, z, x, c, v, b, n, m");
    _dg->program();
    circle_ = positionPointcloud(circle_, 0, 2, 0);
    PointCloud c2 = positionPointcloud(circle_, 0, -2, 0);
    PointCloud c3 = positionPointcloud(circle_, 0, -6, 0);
    PointCloud c4 = positionPointcloud(circle_, 0, 6, 0);


    0;
    std::vector<PointCloud> wave;
    for (int i=0; i<5; i++) {
        PointCloud pc = createSpiralWave(9);
        pc = rotatePointCloud(pc, 0, 90*i, 0);
        wave.push_back(pc);
    }
    255;

    std::vector<PointCloud> vs = { circle_, c2, c3, c4, wave[0], wave[1], wave[2], wave[3] };
    for (int i=0; i<vs.size(); i++) {
        vs[i].colours = colours;
    }



    return vs;
}


void drawActiveBackground(
    int y,
    int x,
    char pixel = ' ')
{
    if (y < 0 || y >= LINES ||
        x < 0 || x >= COLS)
        return;

    chtype current = mvinch(y, x);

    int foregroundPair =
    PAIR_NUMBER(current);

    if (foregroundPair < 1 ||
        foregroundPair > 8)
        return;

    int backgroundPair =
    foregroundPair + 8;

    attron(COLOR_PAIR(backgroundPair));

    mvaddch(
        y,
        x,
        pixel
    );

    attroff(COLOR_PAIR(backgroundPair));
}
