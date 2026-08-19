PointCloud createBall(
    float radius = 5.0f,
    int latitudeSegments = 8,
    int longitudeSegments = 12)
{
    PointCloud sphere;

    constexpr float PI = 3.14159265358979323846f;

    // Top pole.
    sphere.points.push_back({0.0f, radius, 0.0f});
    const int topIndex = 0;

    // Latitude rings, excluding the poles.
    for (int latitude = 1; latitude < latitudeSegments; ++latitude)
    {
        const float phi =
            PI * static_cast<float>(latitude) /
            static_cast<float>(latitudeSegments);

        const float y = radius * std::cos(phi);
        const float ringRadius = radius * std::sin(phi);

        for (int longitude = 0;
             longitude < longitudeSegments;
             ++longitude)
        {
            const float theta =
                2.0f * PI * static_cast<float>(longitude) /
                static_cast<float>(longitudeSegments);

            sphere.points.push_back({
                ringRadius * std::cos(theta),
                y,
                ringRadius * std::sin(theta)
            });
        }
    }

    // Bottom pole.
    const int bottomIndex =
        static_cast<int>(sphere.points.size());

    sphere.points.push_back({0.0f, -radius, 0.0f});

    const int ringCount = latitudeSegments - 1;

    // Horizontal edges around each ring.
    for (int ring = 0; ring < ringCount; ++ring)
    {
        const int ringStart =
            1 + ring * longitudeSegments;

        for (int longitude = 0;
             longitude < longitudeSegments;
             ++longitude)
        {
            const int next =
                (longitude + 1) % longitudeSegments;

            sphere.edges.push_back({
                ringStart + longitude,
                ringStart + next
            });
        }
    }

    // Vertical edges between rings.
    for (int ring = 0; ring < ringCount - 1; ++ring)
    {
        const int currentRing =
            1 + ring * longitudeSegments;

        const int nextRing =
            currentRing + longitudeSegments;

        for (int longitude = 0;
             longitude < longitudeSegments;
             ++longitude)
        {
            sphere.edges.push_back({
                currentRing + longitude,
                nextRing + longitude
            });
        }
    }

    // Connect poles.
    const int firstRing = 1;
    const int lastRing =
        1 + (ringCount - 1) * longitudeSegments;

    for (int longitude = 0;
         longitude < longitudeSegments;
         ++longitude)
    {
        sphere.edges.push_back({
            topIndex,
            firstRing + longitude
        });

        sphere.edges.push_back({
            lastRing + longitude,
            bottomIndex
        });
    }

    return sphere;
}


#include <cmath>

PointCloud createSphere(float radius = 5.0f)
{
    PointCloud sphere;

    constexpr float PI = 3.14159265358979323846f;

    // Vertical positions and ring radii.
    const float upperY = radius * 0.5f;
    const float middleY = 0.0f;
    const float lowerY = -radius * 0.5f;

    const float upperRadius = radius * 0.75f;
    const float middleRadius = radius;
    const float lowerRadius = radius * 0.75f;

    // Point indices:
    //
    // 0       top
    // 1-4     upper ring
    // 5-12    middle ring
    // 13-16   lower ring
    // 17      bottom

    const int topIndex = 0;
    sphere.points.push_back({0.0f, radius, 0.0f});

    const int upperStart =
    static_cast<int>(sphere.points.size());

    // Upper ring: 4 points.
    for (int i = 0; i < 4; ++i)
    {
        const float angle =
        2.0f * PI * static_cast<float>(i) / 4.0f;

        sphere.points.push_back({
            upperRadius * std::cos(angle),
                                upperY,
                                upperRadius * std::sin(angle)
        });
    }

    const int middleStart =
    static_cast<int>(sphere.points.size());

    // Middle ring: 8 points.
    for (int i = 0; i < 8; ++i)
    {
        const float angle =
        2.0f * PI * static_cast<float>(i) / 8.0f;

        sphere.points.push_back({
            middleRadius * std::cos(angle),
                                middleY,
                                middleRadius * std::sin(angle)
        });
    }

    const int lowerStart =
    static_cast<int>(sphere.points.size());

    // Lower ring: 4 points.
    // Offset by 45 degrees so it sits between middle-ring points.
    for (int i = 0; i < 4; ++i)
    {
        const float angle =
        2.0f * PI * static_cast<float>(i) / 4.0f
        + PI / 4.0f;

        sphere.points.push_back({
            lowerRadius * std::cos(angle),
                                lowerY,
                                lowerRadius * std::sin(angle)
        });
    }

    const int bottomIndex =
    static_cast<int>(sphere.points.size());

    sphere.points.push_back({0.0f, -radius, 0.0f});

    // Connect top point to all 4 upper-ring points.
    for (int i = 0; i < 4; ++i)
    {
        sphere.edges.push_back({
            topIndex,
            upperStart + i
        });
    }

    // Connect upper ring horizontally.
    for (int i = 0; i < 4; ++i)
    {
        sphere.edges.push_back({
            upperStart + i,
            upperStart + ((i + 1) % 4)
        });
    }

    // Connect each upper-ring point to two middle-ring points.
    for (int i = 0; i < 4; ++i)
    {
        const int middleA = middleStart + i * 2;
        const int middleB = middleStart + ((i * 2 + 1) % 8);

        sphere.edges.push_back({
            upperStart + i,
            middleA
        });

        sphere.edges.push_back({
            upperStart + i,
            middleB
        });
    }

    // Connect middle ring horizontally.
    for (int i = 0; i < 8; ++i)
    {
        sphere.edges.push_back({
            middleStart + i,
            middleStart + ((i + 1) % 8)
        });
    }

    // Connect each lower-ring point to two middle-ring points.
    for (int i = 0; i < 4; ++i)
    {
        const int middleA = middleStart + ((i * 2 + 1) % 8);
        const int middleB = middleStart + ((i * 2 + 2) % 8);

        sphere.edges.push_back({
            lowerStart + i,
            middleA
        });

        sphere.edges.push_back({
            lowerStart + i,
            middleB
        });
    }

    // Connect lower ring horizontally.
    for (int i = 0; i < 4; ++i)
    {
        sphere.edges.push_back({
            lowerStart + i,
            lowerStart + ((i + 1) % 4)
        });
    }

    // Connect all lower-ring points to the bottom point.
    for (int i = 0; i < 4; ++i)
    {
        sphere.edges.push_back({
            lowerStart + i,
            bottomIndex
        });
    }

    return sphere;
}

#include <vector>
#include <cmath>
#include <map>
#include <utility>

PointCloud createTriangularSphere(float radius = 1.0f, int density = 2)
{
    PointCloud cloud;

    if (density < 1)
        density = 1;

    const float phi = (1.0f + std::sqrt(5.0f)) / 2.0f;

    // Start with an icosahedron.
    std::vector<Point3D> vertices =
    {
        {-1,  phi,  0}, { 1,  phi,  0},
        {-1, -phi,  0}, { 1, -phi,  0},

        { 0, -1,  phi}, { 0,  1,  phi},
        { 0, -1, -phi}, { 0,  1, -phi},

        { phi,  0, -1}, { phi,  0,  1},
        {-phi,  0, -1}, {-phi,  0,  1}
    };

    struct Triangle
    {
        int a;
        int b;
        int c;
    };

    std::vector<Triangle> triangles =
    {
        {0,11,5}, {0,5,1},  {0,1,7},  {0,7,10}, {0,10,11},
        {1,5,9},  {5,11,4}, {11,10,2},{10,7,6}, {7,1,8},

        {3,9,4},  {3,4,2},  {3,2,6},  {3,6,8},  {3,8,9},
        {4,9,5},  {2,4,11}, {6,2,10}, {8,6,7},  {9,8,1}
    };

    // Normalize the original icosahedron onto the sphere.
    auto normalize = [radius](Point3D p)
    {
        float len = std::sqrt(
            p.x * p.x +
            p.y * p.y +
            p.z * p.z
        );

        p.x = (p.x / len) * radius;
        p.y = (p.y / len) * radius;
        p.z = (p.z / len) * radius;

        return p;
    };

    for (auto& p : vertices)
        p = normalize(p);

    /*
     *       density = number of subdivision passes
     *
     *       1 -> 80 triangles
     *       2 -> 320 triangles
     *       3 -> 1280 triangles
     *       4 -> 5120 triangles
     *       5 -> 20480 triangles
     */

    for (int level = 0; level < density; ++level)
    {
        std::map<std::pair<int,int>, int> midpointCache;

        auto getMidpoint = [&](int a, int b)
        {
            if (a > b)
                std::swap(a, b);

            std::pair<int,int> key = {a,b};

            auto found = midpointCache.find(key);

            if (found != midpointCache.end())
                return found->second;

            Point3D midpoint =
            {
                (vertices[a].x + vertices[b].x) * 0.5f,
                (vertices[a].y + vertices[b].y) * 0.5f,
                (vertices[a].z + vertices[b].z) * 0.5f
            };

            midpoint = normalize(midpoint);

            int index = (int)vertices.size();

            vertices.push_back(midpoint);

            midpointCache[key] = index;

            return index;
        };

        std::vector<Triangle> newTriangles;

        newTriangles.reserve(triangles.size() * 4);

        for (const Triangle& t : triangles)
        {
            int ab = getMidpoint(t.a, t.b);
            int bc = getMidpoint(t.b, t.c);
            int ca = getMidpoint(t.c, t.a);

            newTriangles.push_back({
                t.a, ab, ca
            });

            newTriangles.push_back({
                t.b, bc, ab
            });

            newTriangles.push_back({
                t.c, ca, bc
            });

            newTriangles.push_back({
                ab, bc, ca
            });
        }

        triangles = std::move(newTriangles);
    }

    cloud.points = vertices;

    // Add triangle edges without duplicates.
    std::map<std::pair<int,int>, bool> edgeCache;

    auto addEdge = [&](int a, int b)
    {
        if (a > b)
            std::swap(a, b);

        std::pair<int,int> key = {a,b};

        if (edgeCache.find(key) != edgeCache.end())
            return;

        edgeCache[key] = true;

        cloud.edges.push_back({
            a,
            b
        });
    };

    for (const Triangle& t : triangles)
    {
        addEdge(t.a, t.b);
        addEdge(t.b, t.c);
        addEdge(t.c, t.a);
    }

    return cloud;
}
