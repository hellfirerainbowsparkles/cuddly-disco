PointCloud createSquare()
{
    PointCloud square;

    square.points =
    {
        {-5.0f, 0.0f, -5.0f}, // 0
        { 5.0f, 0.0f, -5.0f}, // 1
        { 5.0f, 0.0f,  5.0f}, // 2
        {-5.0f, 0.0f,  5.0f}  // 3
    };

    square.edges =
    {
        {0,1},
        {1,2},
        {2,3},
        {3,0}
    };

    return square;
}


PointCloud createSquareWithCircle()
{
    PointCloud shape;

    constexpr float PI = 3.14159265358979323846f;
    constexpr float radius = 5.0f;
    constexpr int circlePoints = 32;

    // Square: indices 0-3.
    shape.points =
    {
        {-5.0f, 0.0f, -5.0f},
        { 5.0f, 0.0f, -5.0f},
        { 5.0f, 0.0f,  5.0f},
        {-5.0f, 0.0f,  5.0f}
    };

    shape.edges =
    {
        {0,1},
        {1,2},
        {2,3},
        {3,0}
    };

    const int circleStart = 4;

    // Circle: indices 4-35.
    for (int i = 0; i < circlePoints; ++i)
    {
        float angle =
        2.0f * PI *
        static_cast<float>(i) /
        static_cast<float>(circlePoints);

        shape.points.push_back(
            {
                radius * std::cos(angle),
                               0.0f,
                               radius * std::sin(angle)
            });
    }

    for (int i = 0; i < circlePoints; ++i)
    {
        shape.edges.push_back(
            {
                circleStart + i,
                circleStart + ((i + 1) % circlePoints)
            });
    }

    return shape;
}
