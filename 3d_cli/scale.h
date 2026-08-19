Point3D scalePoint3D(
    const Point3D& point,
    float scaleX,
    float scaleY,
    float scaleZ)
{
    return {
        point.x * scaleX,
        point.y * scaleY,
        point.z * scaleZ
    };
}

PointCloud scalePointCloud(
    const PointCloud& cloud,
    float scaleX,
    float scaleY,
    float scaleZ)
{
    PointCloud result = cloud;

    for (Point3D& point : result.points)
    {
        point = scalePoint3D(
            point,
            scaleX,
            scaleY,
            scaleZ
        );
    }

    return result;
}


