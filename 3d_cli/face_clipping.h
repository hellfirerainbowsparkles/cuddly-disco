#include <vector>
#include <limits>
#include <algorithm>
#include <cmath>
/*
struct Face
{
    std::vector<int> points;
};*/

static std::vector<std::vector<double>> faceDepthBuffer;

void initFaceDepthBuffer()
{
    faceDepthBuffer.assign(
        LINES,
        std::vector<double>(
            COLS,
            std::numeric_limits<double>::infinity()
        )
    );
}

void clearFaceDepthBuffer()
{
    for (int y = 0; y < LINES; ++y)
    {
        for (int x = 0; x < COLS; ++x)
        {
            faceDepthBuffer[y][x] =
                std::numeric_limits<double>::infinity();
        }
    }
}

double edgeFunction(
    double ax,
    double ay,
    double bx,
    double by,
    double px,
    double py)
{
    return
        (px - ax) * (by - ay) -
        (py - ay) * (bx - ax);
}

void rasterizeTriangleDepth(
    const Point3D& a,
    const Point3D& b,
    const Point3D& c,
    const Camera& camera,
    float cameraDistance = CAMERA_DISTANCE)
{
    Point3D ca = worldToCamera(a, camera);
    Point3D cb = worldToCamera(b, camera);
    Point3D cc = worldToCamera(c, camera);

    double da = ca.z + cameraDistance;
    double db = cb.z + cameraDistance;
    double dc = cc.z + cameraDistance;

    if (da <= 0.1 ||
        db <= 0.1 ||
        dc <= 0.1)
        return;

    ScreenPoint sa =
        projectPoint(a, camera, cameraDistance);

    ScreenPoint sb =
        projectPoint(b, camera, cameraDistance);

    ScreenPoint sc =
        projectPoint(c, camera, cameraDistance);

    if (!sa.visible ||
        !sb.visible ||
        !sc.visible)
        return;

    int minX = std::max(
        0,
        std::min({
            sa.x,
            sb.x,
            sc.x
        })
    );

    int maxX = std::min(
        COLS - 1,
        std::max({
            sa.x,
            sb.x,
            sc.x
        })
    );

    int minY = std::max(
        0,
        std::min({
            sa.y,
            sb.y,
            sc.y
        })
    );

    int maxY = std::min(
        LINES - 1,
        std::max({
            sa.y,
            sb.y,
            sc.y
        })
    );

    double area =
        edgeFunction(
            sa.x,
            sa.y,
            sb.x,
            sb.y,
            sc.x,
            sc.y
        );

    if (std::abs(area) < 0.000001)
        return;

    for (int y = minY; y <= maxY; ++y)
    {
        for (int x = minX; x <= maxX; ++x)
        {
            double px = x + 0.5;
            double py = y + 0.5;

            double w0 =
                edgeFunction(
                    sb.x,
                    sb.y,
                    sc.x,
                    sc.y,
                    px,
                    py
                );

            double w1 =
                edgeFunction(
                    sc.x,
                    sc.y,
                    sa.x,
                    sa.y,
                    px,
                    py
                );

            double w2 =
                edgeFunction(
                    sa.x,
                    sa.y,
                    sb.x,
                    sb.y,
                    px,
                    py
                );

            bool inside =
                (w0 >= 0 &&
                 w1 >= 0 &&
                 w2 >= 0) ||

                (w0 <= 0 &&
                 w1 <= 0 &&
                 w2 <= 0);

            if (!inside)
                continue;

            w0 /= area;
            w1 /= area;
            w2 /= area;

            double depth =
                da * w0 +
                db * w1 +
                dc * w2;

            if (depth < faceDepthBuffer[y][x])
            {
                faceDepthBuffer[y][x] =
                    depth;
            }
        }
    }
}

void rasterizeFaceDepth(
    const PointCloud& pointcloud,
    const Face& face,
    const Camera& camera,
    float cameraDistance = CAMERA_DISTANCE)
{
    if (face.points.size() < 3)
        return;

    int first = face.points[0];

    for (int i = 1;
         i < static_cast<int>(face.points.size()) - 1;
         ++i)
    {
        int second = face.points[i];
        int third  = face.points[i + 1];

        rasterizeTriangleDepth(
            pointcloud.points[first],
            pointcloud.points[second],
            pointcloud.points[third],
            camera,
            cameraDistance
        );
    }
}

void rasterizePointCloudFaces(
    const PointCloud& pointcloud,
    const std::vector<Face>& faces,
    const Camera& camera,
    float cameraDistance = CAMERA_DISTANCE)
{
    for (const Face& face : faces)
    {
        rasterizeFaceDepth(
            pointcloud,
            face,
            camera,
            cameraDistance
        );
    }
}
