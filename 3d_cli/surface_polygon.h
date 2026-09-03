#include <cmath>

PointCloud createSurfacePolygon(
    int sides,
    double radius = 5.0,
    double y = 0.0)
{
    PointCloud polygon;

    if (sides < 3)
        return polygon;

    constexpr double PI =
        3.14159265358979323846;

    // Create points on the X/Z surface plane.
    for (int i = 0; i < sides; ++i)
    {
        double angle =
            (2.0 * PI * i / sides)
            - PI / 2.0;

        polygon.points.push_back(
        {
            radius * std::cos(angle),
            y,
            radius * std::sin(angle)
        });
    }

    // Connect each point to the next.
    for (int i = 0; i < sides; ++i)
    {
        polygon.edges.push_back(
        {
            i,
            (i + 1) % sides
        });
    }

    return polygon;
}

std::vector<Point3D> createSurfacePolygonCenters(
    int amount,
    double radius)
{
    std::vector<Point3D> points;

    double diameter = radius * 2.0;

    for (int i = 0; i < amount; ++i)
    {
        points.push_back({
            static_cast<double>(i) * diameter,
                         0.0,
                         0.0
        });
    }

    return points;
}

PointCloud createSurfacePolygonsAtPoints(
    const std::vector<Point3D>& points,
    int n,
    double radius = 5.0)
{
    PointCloud result;

    for (const Point3D& center : points)
    {
        PointCloud polygon =
        createSurfacePolygon(
            n,
            radius,
            center.z
        );

        // Move polygon so its center is at the supplied X/Y position.
        for (Point3D& point : polygon.points)
        {
            point.x += center.x;
            point.y += center.y;
        }

        result =
        joinPointClouds(
            result,
            polygon
        );
    }

    return result;
}

PointCloud createPath(
    int amount,
    double radius,
    int sides)
{
    std::vector<Point3D> centers =
    createSurfacePolygonCenters(
        amount,
        radius
    );

    return createSurfacePolygonsAtPoints(
        centers,
        sides,
        radius
    );
}
