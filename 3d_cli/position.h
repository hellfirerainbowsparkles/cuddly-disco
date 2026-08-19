PointCloud positionPointcloud(
    const PointCloud& cloud,
    float x,
    float y,
    float z)
{
    PointCloud positioned = cloud;

    for (Point3D& point : positioned.points)
    {
        point.x += x;
        point.y += y;
        point.z += z;
    }

    return positioned;
}
