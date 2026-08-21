std::map<std::string, Dialog> dialogs;


void createDialogs()
{
    dialogs["render_mode"] =
    {
        "render_mode",
        "Render Mode",

        {
            {"Wireframe", 0},
            {"Vertices",  1},
            {"Both",      2}
        },

        0
    };


    dialogs["camera_speed"] =
    {
        "camera_speed",
        "Camera Speed",

        {
            {"Slow",   1},
            {"Normal", 2},
            {"Fast",   3}
        },

        1
    };


    dialogs["colour_mode"] =
    {
        "colour_mode",
        "Colour Mode",

        {
            {"Object colours", 0},
            {"Scene colours",  1},
            {"Monochrome",     2}
        },

        0
    };
}


