#include <cmath>

PointCloud createCubeWithFaceCircles(float scale = 5.0)
{
    PointCloud shape;

    constexpr double PI = 3.14159265358979323846;
    constexpr int CIRCLE_POINTS = 32;

    const float HALF = scale;

    // --------------------------------------------------
    // Cube vertices
    // --------------------------------------------------

    shape.points =
    {
        {-HALF,-HALF,-HALF}, // 0
        { HALF,-HALF,-HALF}, // 1
        { HALF, HALF,-HALF}, // 2
        {-HALF, HALF,-HALF}, // 3

        {-HALF,-HALF, HALF}, // 4
        { HALF,-HALF, HALF}, // 5
        { HALF, HALF, HALF}, // 6
        {-HALF, HALF, HALF}  // 7
    };

    shape.edges =
    {
        {0,1}, {1,2}, {2,3}, {3,0},
        {4,5}, {5,6}, {6,7}, {7,4},
        {0,4}, {1,5}, {2,6}, {3,7}
    };

    auto addCircle =
    [&](int axis, double position)
    {
        int start =
        static_cast<int>(shape.points.size());

        for (int i = 0; i < CIRCLE_POINTS; ++i)
        {
            double angle =
            2.0 * PI *
            static_cast<double>(i) /
            static_cast<double>(CIRCLE_POINTS);

            double a = HALF * std::cos(angle);
            double b = HALF * std::sin(angle);

            Point3D p;

            switch(axis)
            {
                case 0: // YZ plane
                    p =
                    {
                        static_cast<float>(a),
                        static_cast<float>(position),
                        static_cast<float>(b)
                    };
                    break;

                case 1: // XZ plane
                    p =
                    {
                        static_cast<float>(a),
                        static_cast<float>(position),
                        static_cast<float>(b)
                    };
                    break;

                default: // XY plane
                    p =
                    {
                        static_cast<float>(a),
                        static_cast<float>(position),
                        static_cast<float>(b)
                    };
                    break;
            }

            shape.points.push_back(p);
        }

        for (int i = 0; i < CIRCLE_POINTS; ++i)
        {
            shape.edges.push_back(
                {
                    start + i,
                    start + ((i + 1) % CIRCLE_POINTS)
                });
        }
    };

    // Left / Right
    addCircle(0, -HALF);
    addCircle(0,  HALF);

    // Bottom / Top
    addCircle(1, -HALF);
    addCircle(1,  HALF);

    // Back / Front
    addCircle(2, -HALF);
    addCircle(2,  HALF);

    return shape;
}
