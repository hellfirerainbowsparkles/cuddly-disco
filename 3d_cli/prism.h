PointCloud createPrism(
    int n,
    double d,
    bool bothSides,
    double radius = 5.0)
{
    PointCloud result =
        createSurfacePolygon(
            n,
            radius,
            0.0
        );

    if (n < 3)
        return result;

    // Polygon is on X/Z plane, so Y is up/down.
    int topIndex =
        static_cast<int>(result.points.size());

    result.points.push_back({
        0.0,
        d,
        0.0
    });

    // Connect top point to every polygon vertex.
    for (int i = 0; i < n; ++i)
    {
        result.edges.push_back({
            topIndex,
            i
        });
    }

    if (bothSides)
    {
        int bottomIndex =
            static_cast<int>(result.points.size());

        result.points.push_back({
            0.0,
            -d,
            0.0
        });

        // Connect bottom point to every polygon vertex.
        for (int i = 0; i < n; ++i)
        {
            result.edges.push_back({
                bottomIndex,
                i
            });
        }
    }

    return result;
}
