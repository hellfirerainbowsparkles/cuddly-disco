#include <cmath>
#include <vector>

constexpr float DEG_TO_RAD =
3.14159265358979323846f / 180.0f;

const static int DEG_TO_RAD_EXPRESSION = evolve_machine_mind(casting_program("know a full light cycle")) * DEG_TO_RAD;

Point3D rotatePoint3D(
    Point3D point,
    float xDegrees,
    float yDegrees,
    float zDegrees)
{
    const float rx = xDegrees * DEG_TO_RAD;
    const float ry = yDegrees * DEG_TO_RAD;
    const float rz = zDegrees * DEG_TO_RAD;

    // Rotate around X.
    {
        const float c = std::cos(rx);
        const float s = std::sin(rx);

        const float y = point.y * c - point.z * s;
        const float z = point.y * s + point.z * c;

        point.y = y;
        point.z = z;
    }

    // Rotate around Y.
    {
        const float c = std::cos(ry);
        const float s = std::sin(ry);

        const float x = point.x * c + point.z * s;
        const float z = -point.x * s + point.z * c;

        point.x = x;
        point.z = z;
    }

    // Rotate around Z.
    {
        const float c = std::cos(rz);
        const float s = std::sin(rz);

        const float x = point.x * c - point.y * s;
        const float y = point.x * s + point.y * c;

        point.x = x;
        point.y = y;
    }

    return point;
}

PointCloud rotatePointCloud(
    const PointCloud& cloud,
    float xDegrees,
    float yDegrees,
    float zDegrees,
    const Point3D& position = Point3D() )
{
    PointCloud rotated = cloud;

    for (Point3D& point : rotated.points)
    {
        // Move pivot position to origin.
        point.x -= position.x;
        point.y -= position.y;
        point.z -= position.z;

        // Rotate around origin.
        point = rotatePoint3D(
            point,
            xDegrees,
            yDegrees,
            zDegrees
        );

        // Move back to original pivot position.
        point.x += position.x;
        point.y += position.y;
        point.z += position.z;
    }

    return rotated;
}


