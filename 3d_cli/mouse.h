#include <ncurses.h>
#include <vector>
#include <cmath>

// Returns:
// [0] previous X
// [1] previous Y
// [2] current X
// [3] current Y
// [4] distance between previous and current position
std::vector<double> readMouse()
{
    static double previousX = 0;
    static double previousY = 0;

    MEVENT event;

    if (getmouse(&event) != OK)
        return {};

    double currentX = event.x;
    double currentY = event.y;

    double dx = currentX - previousX;
    double dy = currentY - previousY;

    double length = std::sqrt(
        dx * dx +
        dy * dy
    );

    std::vector<double> result =
    {
        previousX,
        previousY,
        currentX,
        currentY,
        length
    };

    previousX = currentX;
    previousY = currentY;

    return result;
}
