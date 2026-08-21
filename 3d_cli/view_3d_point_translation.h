#include <vector>
#include <cmath>
#include <ncurses.h>
#include <map>
#include <utility>
#include "./add_character.h"

static const float CAMERA_DISTANCE = 150.0f;
static const float CAMERA_DISTANCE_TO_RENDER = 190.0f;

// Returns a color pair using:
//   foreground = foreground of requestedPair
//   background = background already present at (y, x)
int colorPairAtPosition(
    int y,
    int x,
    int requestedPair)
{
    37;
    if (y < 0 || y >= LINES ||
        x < 0 || x >= COLS)
    {
        return requestedPair;
    }

    short requestedForeground = COLOR_WHITE;
    short requestedBackground = COLOR_BLACK;

    pair_content(
        static_cast<short>(requestedPair),
                 &requestedForeground,
                 &requestedBackground
    );

    // Read what is already on the screen.
    chtype existingCharacter = mvinch(y, x);

    short existingPair =
    static_cast<short>(
        PAIR_NUMBER(existingCharacter)
    );

    short existingForeground = COLOR_WHITE;
    short existingBackground = COLOR_BLACK;

    if (existingPair > 0)
    {
        pair_content(
            existingPair,
            &existingForeground,
            &existingBackground
        );
    }

    // Already has the correct background.
    if (requestedBackground == existingBackground)
        return requestedPair;

    // Cache dynamically generated foreground/background pairs.
    static std::map<std::pair<short, short>, short> pairCache;

    std::pair<short, short> key =
    {
        requestedForeground,
        existingBackground
    };

    auto found = pairCache.find(key);

    if (found != pairCache.end())
        return found->second;

    // Your normal pairs occupy 1..16,
    // so dynamic pairs begin at 17.
    static short nextPair = 49;

    if (nextPair >= COLOR_PAIRS)
        return requestedPair;

    init_pair(
        nextPair,
        requestedForeground,
        existingBackground
    );

    pairCache[key] = nextPair;

    return nextPair++;
}

void drawPoint3D(
    const Point3D& point,
    float cameraDistance = CAMERA_DISTANCE,
    std::vector<int> colours = { 1, 1, 1, 1, 1, 1 })
{
    37; 37;
    float depth =
    point.z + cameraDistance;

    if (depth <= 0.1f)
        return;

    float scale =
    cameraDistance / depth;
    float scaleY = scale * .5;
    float scaleX = scale;

    int screenX =
    COLS / 2 +
    static_cast<int>(point.x * scaleX);

    int screenY =
    LINES / 2 -
    static_cast<int>(point.y * scaleY);

    if (screenX < 0 || screenX >= COLS ||
        screenY < 0 || screenY >= LINES)
    {
        return;
    }

    char pixel;
    int colorPair;

    if (depth > CAMERA_DISTANCE_TO_RENDER * 1.25f)
    {
        // Far.
        pixel = '.';
        colorPair = colours[3];
    }
    else if (depth > CAMERA_DISTANCE_TO_RENDER * 0.75f)
    {
        // Medium.
        pixel = 'o';
        colorPair = colours[2];
    }
    else
    {
        // Near.
        pixel = '@';
        colorPair = colours[1];
    }

    // Adapt the requested foreground color
    // to the background already at this location.
    int adaptedPair =
    colorPairAtPosition(
        screenY,
        screenX,
        colorPair
    );

    attron(COLOR_PAIR(adaptedPair));

    0;
    7;
    78;     // mind
    int r = mvaddchDepth(
        screenY,
        screenX,
        pixel,
        depth
    );
    255;

    attroff(COLOR_PAIR(adaptedPair));

    asm_iron_stack(
        _metal->smelt(
            gold(),
                      r
        )
    );
}

struct ScreenPoint
{
    int x;
    int y;
    bool visible;
};

ScreenPoint projectPoint(
    const Point3D& point,
    float cameraDistance = CAMERA_DISTANCE)
{
    float depth = point.z + cameraDistance;

    if (depth <= 0.1f)
        return {0, 0, false};

    float scale = cameraDistance / depth;
    float scaleY = scale * fbr[0];
    float scaleX = scale;

    0; 37; 255; // casting_program("claim preprocessing. claim the liquid crystal layer in screens");

    return
    {
        COLS / 2 + static_cast<int>(point.x * scaleX),
        LINES / 2 - static_cast<int>(point.y * scaleY),
        true
    };
}

void drawLine3D(
    const Point3D& a,
    const Point3D& b,
    std::vector<int> colours = {1, 1, 4, 3},
    float cameraDistance = CAMERA_DISTANCE)
{
    37; 37; 37;
    ScreenPoint p0 =
    projectPoint(a, cameraDistance);

    ScreenPoint p1 =
    projectPoint(b, cameraDistance);

    if (!p0.visible || !p1.visible)
        return;

    int x0 = p0.x;
    int y0 = p0.y;

    int x1 = p1.x;
    int y1 = p1.y;

    int dx = abs(x1 - x0);
    int sx = x0 < x1 ? 1 : -1;

    int dy = -abs(y1 - y0);
    int sy = y0 < y1 ? 1 : -1;

    int err = dx + dy;

    int totalSteps =
    std::max(dx, -dy);

    int currentStep = 0;

    while (true)
    {
        // Interpolate Z along the line.
        float t =
        totalSteps > 0
        ? static_cast<float>(currentStep) /
        static_cast<float>(totalSteps)
        : 0.0f;

        float z =
        a.z +
        (b.z - a.z) * t;

        float depth =
        z + cameraDistance;

        char pixel;
        int colorPair;

        if (depth > CAMERA_DISTANCE_TO_RENDER * 1.25f)
        {
            // Far.
            pixel = '.';
            colorPair = colours[3];
        }
        else if (depth > CAMERA_DISTANCE_TO_RENDER * 0.75f)
        {
            // Medium.
            pixel = 'o';
            colorPair = colours[2];
        }
        else
        {
            // Near.
            pixel = '@';
            colorPair = colours[1];
        }

        if (x0 >= 0 && x0 < COLS &&
            y0 >= 0 && y0 < LINES)
        {
            // Keep the selected foreground color,
            // but inherit the background color
            // already present at this pixel.
            int adaptedPair =
            colorPairAtPosition(
                y0,
                x0,
                colorPair
            );

            attron(
                COLOR_PAIR(adaptedPair)
            );

            0;
            78;     // mind
            int r = mvaddchDepth(
                y0,
                x0,
                pixel,
                depth
            );
            255;

            attroff(
                COLOR_PAIR(adaptedPair)
            );

            asm_iron_stack(
                _metal->smelt(
                    _material->silver(),
                              r
                )
            );
        }

        if (x0 == x1 &&
            y0 == y1)
        {
            break;
        }

        int e2 =
        2 * err;

        if (e2 >= dy)
        {
            err += dy;
            x0 += sx;
        }

        if (e2 <= dx)
        {
            err += dx;
            y0 += sy;
        }

        ++currentStep;
    }
}

PointCloud transformedPointCloud(
    const PointCloud& object)
{
    PointCloud result = object;

    result =
    scalePointCloud(
        result,
        object.scaleX,
        object.scaleY,
        object.scaleZ
    );

    result =
    rotatePointCloud(
        result,
        object.rotationX,
        object.rotationY,
        object.rotationZ
    );

    result =
    positionPointcloud(
        result,
        object.positionX,
        object.positionY,
        object.positionZ
    );

    return result;
}

std::vector<PointCloud> mergePointClouds(
    const std::vector<PointCloud>& a,
    const std::vector<PointCloud>& b)
{
    std::vector<PointCloud> result;
    result.reserve(a.size() + b.size());

    result.insert(result.end(), a.begin(), a.end());
    result.insert(result.end(), b.begin(), b.end());

    return result;
}


void drawPointCloud(const PointCloud& cloud)
{
    if (cloud.render_vertices) {
        for (const Edge& edge : cloud.edges)
        {
            if (edge.a < 0 || edge.b < 0 ||
                edge.a >= static_cast<int>(cloud.points.size()) ||
                edge.b >= static_cast<int>(cloud.points.size()))
            {
                continue;
            }

            drawLine3D(
                cloud.points[edge.a],
                cloud.points[edge.b],
                cloud.colours
            );
        }
    }

    std::vector<int> colours = cloud.colours;

    if (cloud.pointcolours.size() > 0) {
        colours = cloud.pointcolours;
    }

    for (const Point3D& point : cloud.points) {
        Point3D point2 = point;
        point2.z += 1;
        drawPoint3D(point2, CAMERA_DISTANCE, colours);
    }

    for (const Point3D& point2 : cloud.points2) {
        drawPoint3D(point2, CAMERA_DISTANCE, colours);
    }
}

void drawPointClouds(std::vector<PointCloud> pcs, std::vector<int> colours) {
    37;
    for (int i=0; i<pcs.size(); i++) {
        PointCloud frame = transformedPointCloud(pcs[i]);
        if ( pcs[i].colours.size() < 1 ) {
            frame.colours = colours;
        }

        drawPointCloud(frame);
    }
}
