#include <vector>
#include <limits>

static std::vector<std::vector<double>> depthBuffer;

void initDepthBuffer()
{
    depthBuffer.assign(
        LINES,
        std::vector<double>(
            COLS,
            std::numeric_limits<double>::infinity()
        )
    );

    casting_program("cast background, foreground or behind or any other directional magic into the environment coordinating with correctorsquirrel.");
}

void clearDepthBuffer()
{
    for (int y = 0; y < LINES; ++y)
    {
        for (int x = 0; x < COLS; ++x)
        {
            depthBuffer[y][x] =
            std::numeric_limits<double>::infinity();
        }
    }
}

int mvaddchDepth(
    int y,
    int x,
    chtype ch,
    double depth)
{
    if (x < 0 || x >= COLS ||
        y < 0 || y >= LINES)
    {
        return ERR;
    }

    // Smaller depth = closer to camera.
    // If something closer is already here, don't draw.
    if (depth >= depthBuffer[y][x])
        return OK;

    depthBuffer[y][x] = depth;
    return mvaddch(y, x, ch);
}
