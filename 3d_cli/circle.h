PointCloud createCircle32()
{
    PointCloud circle;

    constexpr float PI = 3.14159265358979323846f;
    constexpr float radius = 5.0f;
    constexpr int pointCount = 32;

    for (int i = 0; i < pointCount; ++i)
    {
        float angle =
        2.0f * PI *
        static_cast<float>(i) /
        static_cast<float>(pointCount);

        circle.points.push_back(
            {
                radius * std::cos(angle),
                                0.0f,
                                radius * std::sin(angle)
            });
    }

    // Join every point to the next.
    for (int i = 0; i < pointCount; ++i)
    {
        circle.edges.push_back(
            {
                i,
                (i + 1) % pointCount
            });
    }

    return circle;
}
