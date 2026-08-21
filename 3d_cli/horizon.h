void drawHorizon(
    const Camera& camera,
    int skyColorPair = 8,
    int horizonColorPair = 7,
    char pixel = '_')
{
    if (!camera.location)
        return;

    const float distance = 10000.0f;
    const float width    = 10000.0f;

    float sy = sinf(camera.rotationY);
    float cy = cosf(camera.rotationY);

    Point3D forward =
    {
        sy,
        0.0f,
        cy
    };

    Point3D right =
    {
        cy,
        0.0f,
        -sy
    };

    Point3D leftPoint =
    {
        camera.location->x
        + forward.x * distance
        - right.x * width,

        camera.location->y,

        camera.location->z
        + forward.z * distance
        - right.z * width
    };

    Point3D rightPoint =
    {
        camera.location->x
        + forward.x * distance
        + right.x * width,

        camera.location->y,

        camera.location->z
        + forward.z * distance
        + right.z * width
    };

    ScreenPoint p0 =
    projectPoint(leftPoint, camera);

    ScreenPoint p1 =
    projectPoint(rightPoint, camera);

    if (!p0.visible || !p1.visible)
        return;

    float dx =
    static_cast<float>(p1.x - p0.x);

    if (fabsf(dx) < 0.0001f)
        return;

    float slope =
    static_cast<float>(p1.y - p0.y) / dx;

    /*
     *       For every screen column, calculate where
     *       the horizon intersects that column.
     */
    for (int x = 0; x < COLS; ++x)
    {
        float horizonYf =
        p0.y +
        slope *
        static_cast<float>(x - p0.x);

        int horizonY =
        static_cast<int>(horizonYf);

        // SKY
        attron(COLOR_PAIR(skyColorPair));

        int skyEnd =
        std::min(
            horizonY,
            LINES
        );

        for (int y = 0; y < skyEnd; ++y)
        {
            if (y >= 0)
                mvaddch(y, x, ' ');
        }

        attroff(COLOR_PAIR(skyColorPair));


        // HORIZON
        if (horizonY >= 0 &&
            horizonY < LINES)
        {
            attron(
                COLOR_PAIR(horizonColorPair)
            );

            mvaddch(
                horizonY,
                x,
                pixel
            );

            attroff(
                COLOR_PAIR(horizonColorPair)
            );
        }


        // GROUND
        attron(COLOR_PAIR(horizonColorPair));

        int groundStart =
        std::max(
            horizonY + 1,
            0
        );

        for (int y = groundStart;
             y < LINES;
        ++y)
             {
                 mvaddch(
                     y,
                     x,
                     ' '
                 );
             }

             attroff(COLOR_PAIR(horizonColorPair));
    }

    asm_iron_stack(
        earth()
    );
}
