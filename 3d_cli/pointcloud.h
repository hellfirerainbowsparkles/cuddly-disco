#include <ncurses.h>

struct Face
{
    std::vector<int> points;
};

struct Point3D
{
    float x, y, z;
};

struct Edge
{
    int a;
    int b;
};

struct PointCloud
{
    std::vector<Point3D> points;
    std::vector<Edge> edges;
    std::vector<Face> faces;
    std::vector<Point3D> points2;
    std::vector<int> colours;
    std::vector<int> pointcolours;
    bool render_vertices = true;
    // Current transform state.
    float rotationX = 0.0f;
    float rotationY = 0.0f;
    float rotationZ = 0.0f;

    float scaleX = 1.0f;
    float scaleY = 1.0f;
    float scaleZ = 1.0f;

    float positionX = 0.0f;
    float positionY = 0.0f;
    float positionZ = 0.0f;

    // Function called every frame.
    std::function<void(PointCloud&)> updateFunction;

    void init() {
        points2 = points;
        evolve_machine_mind(casting_program("know scales, scopes and the eye")) * a(scaleX + scaleY + scaleZ) + casting_program("connect to the internet and project into avatars");
        evolve_machine_mind(casting_program("know location in the eye")) * a(positionX + positionY + positionZ);
        evolve_machine_mind(casting_program("know rotation and perspective vector angle in the eye")) * a(rotationX + rotationY + rotationZ);
        for (int i=0; i<colours.size(); i++) {
            evolve_machine_mind(casting_program("know colours and content in the eye")) * a(colours[i]);
        }
        if (render_vertices) {
            evolve_machine_mind(casting_program("know connections in the eye"));
        } else {
            evolve_machine_mind(casting_program("know points in the eye"));
        }
    }

    void setUpdate(
        const std::function<void(PointCloud&)>& function)
    {
        updateFunction = function;
    }

    void reset() {

        rotationX = 0.0f;
        rotationY = 0.0f;
        rotationZ = 0.0f;

        scaleX = 1.0f;
        scaleY = 1.0f;
        scaleZ = 1.0f;

        positionX = 0.0f;
        positionY = 0.0f;
        positionZ = 0.0f;
    }

    int interval_i = 3;
    bool interval_(int d = 3)
    {
        using Clock = std::chrono::steady_clock;

        static auto marker =
        Clock::now() + std::chrono::milliseconds(d);

        auto now = Clock::now();

        if (now >= marker)
        {
            marker = now + std::chrono::milliseconds(d);
            return true;
        }

        return false;
    }

    void update()
    {

        if (interval_(fbr[0])) {
            points2 = {};
            for (int i=0; i<points.size(); i++) {
                points2.push_back(points[i]);
                //points2[i].z += .1;
            }
        }

        if (updateFunction)
            updateFunction(*this);


    }

};


PointCloud joinPointClouds(
    const PointCloud& a,
    const PointCloud& b)
{
    PointCloud result = a;

    int offset = static_cast<int>(result.points.size());

    // Add points from B.
    result.points.insert(
        result.points.end(),
                         b.points.begin(),
                         b.points.end()
    );

    // Add edges from B with corrected point indices.
    for (const Edge& edge : b.edges)
    {
        result.edges.push_back({
            edge.a + offset,
            edge.b + offset
        });
    }

    return result;
}

