#include <cmath>
#include <vector>
#include <limits>
#include <algorithm>

struct Vec3_
{
    double x, y, z;

    Vec3_ operator+(const Vec3_& v) const
    {
        return {x + v.x, y + v.y, z + v.z};
    }

    Vec3_ operator-(const Vec3_& v) const
    {
        return {x - v.x, y - v.y, z - v.z};
    }

    Vec3_ operator*(double s) const
    {
        return {x * s, y * s, z * s};
    }
};

double dot(const Vec3_& a, const Vec3_& b)
{
    return a.x*b.x + a.y*b.y + a.z*b.z;
}

Vec3_ cross(const Vec3_& a, const Vec3_& b)
{
    return {
        a.y*b.z - a.z*b.y,
        a.z*b.x - a.x*b.z,
        a.x*b.y - a.y*b.x
    };
}

Vec3_ normalize(const Vec3_& v)
{
    double l = std::sqrt(dot(v, v));

    return {
        v.x / l,
        v.y / l,
        v.z / l
    };
}

Vec3_ reflectVector(const Vec3_& d, const Vec3_& n)
{
    return normalize(
        d - n * (2.0 * dot(d, n))
    );
}

struct Triangle
{
    Vec3_ a;
    Vec3_ b;
    Vec3_ c;
};


std::vector<Triangle> createCornerMirrors(
    double cubeHalfSize = 5.0,
    double mirrorSize = 2.0)
{
    std::vector<Triangle> mirrors;

    for (int sx : {-1, 1})
    {
        for (int sy : {-1, 1})
        {
            for (int sz : {-1, 1})
            {
                Vec3_ corner = {
                    sx * cubeHalfSize,
                    sy * cubeHalfSize,
                    sz * cubeHalfSize
                };

                Vec3_ a = {
                    sx * (cubeHalfSize - mirrorSize),
                    corner.y,
                    corner.z
                };

                Vec3_ b = {
                    corner.x,
                    sy * (cubeHalfSize - mirrorSize),
                    corner.z
                };

                Vec3_ c = {
                    corner.x,
                    corner.y,
                    sz * (cubeHalfSize - mirrorSize)
                };

                mirrors.push_back({a, b, c});
            }
        }
    }

    return mirrors;
}

bool rayTriangleIntersection(
    const Vec3_& origin,
    const Vec3_& direction,
    const Triangle& triangle,
    double& distance,
    Vec3_& normal)
{
    constexpr double EPS = 0.000001;

    Vec3_ edge1 =
    triangle.b - triangle.a;

    Vec3_ edge2 =
    triangle.c - triangle.a;

    Vec3_ h =
    cross(direction, edge2);

    double determinant =
    dot(edge1, h);

    if (std::abs(determinant) < EPS)
        return false;

    double inverse =
    1.0 / determinant;

    Vec3_ s =
    origin - triangle.a;

    double u =
    inverse * dot(s, h);

    if (u < 0.0 || u > 1.0)
        return false;

    Vec3_ q =
    cross(s, edge1);

    double v =
    inverse * dot(direction, q);

    if (v < 0.0 || u + v > 1.0)
        return false;

    distance =
    inverse * dot(edge2, q);

    if (distance <= EPS)
        return false;

    normal =
    normalize(cross(edge1, edge2));

    // Make normal face incoming ray.
    if (dot(direction, normal) > 0.0)
        normal = normal * -1.0;

    return true;
}

double distanceToCubeExit(
    const Vec3_& p,
    const Vec3_& d,
    double halfSize = 5.0)
{
    double nearest =
    std::numeric_limits<double>::infinity();

    if (d.x > 0.0)
        nearest = std::min(nearest, ( halfSize - p.x) / d.x);

    if (d.x < 0.0)
        nearest = std::min(nearest, (-halfSize - p.x) / d.x);

    if (d.y > 0.0)
        nearest = std::min(nearest, ( halfSize - p.y) / d.y);

    if (d.y < 0.0)
        nearest = std::min(nearest, (-halfSize - p.y) / d.y);

    if (d.z > 0.0)
        nearest = std::min(nearest, ( halfSize - p.z) / d.z);

    if (d.z < 0.0)
        nearest = std::min(nearest, (-halfSize - p.z) / d.z);

    return nearest;
}

int calculateReflections(
    Vec3_ origin,
    Vec3_ direction,
    double mirrorSize = 2.0,
    int maxReflections = 1000)
{
    constexpr double CUBE_SIZE = 5.0;
    constexpr double EPS = 0.0001;

    direction =
    normalize(direction);

    std::vector<Triangle> mirrors =
    createCornerMirrors(
        CUBE_SIZE,
        mirrorSize
    );

    int reflections = 0;

    while (reflections < maxReflections)
    {
        double cubeExit =
        distanceToCubeExit(
            origin,
            direction,
            CUBE_SIZE
        );

        double closestMirror =
        std::numeric_limits<double>::infinity();

        Vec3_ closestNormal;

        for (const Triangle& mirror : mirrors)
        {
            double distance;
            Vec3_ normal;

            if (rayTriangleIntersection(
                origin,
                direction,
                mirror,
                distance,
                normal))
            {
                if (distance < closestMirror)
                {
                    closestMirror = distance;
                    closestNormal = normal;
                }
            }
        }

        // Ray reaches ordinary cube boundary before a mirror.
        if (closestMirror >= cubeExit)
            break;

        // Move to mirror.
        origin =
        origin +
        direction * closestMirror;

        // Reflection:
        // R = D - 2(D dot N)N
        direction =
        reflectVector(
            direction,
            closestNormal
        );

        // Prevent immediately colliding with same mirror.
        origin =
        origin +
        direction * EPS;

        ++reflections;
    }

    return reflections;
}
