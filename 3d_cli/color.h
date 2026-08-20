#include <vector>
#include <algorithm>


std::vector<int> crystalcolours[11] = {
    { 4, 4, 5, 6, 5, 6+24 },   // water
    { 11, 11, 12, 13, 17, 12+24 },    // red
    { 23, 22, 23, 24, 5, -1, -1, 0 },   // space
    { 1, 1, 1, 1, 1, 1 },       // white
    { 3, 3, 3, 3, 3, 3 },       // black
    { 7, 7, 8, 9, 8, 8 },       // green
    { 17, 17, 14, 11, -1, -1 },   // gold / yellow
    { 19, 19, 20, 21, -1, -1 },    // pink
    { 13, 13, 14, 15, -1, -1 },     // orange
    { 1, 4, 4, 22, -1, -1 },         // lightblue
    { 1, 1, 1, 1, 1, 1 },       // rainbow (loop through colour pairs like {red, orang, pink, gold, white} )
};

int findColorForString(const std::string& color)
{
    if (color == "water")     return 0;
    if (color == "red")       return 1;
    if (color == "space")     return 2;
    if (color == "white")     return 3;
    if (color == "black")     return 4;
    if (color == "green")     return 5;
    if (color == "gold" || color == "yellow")    return 6;
    if (color == "pink")      return 7;
    if (color == "orange")    return 8;
    if (color == "lightblue") return 9;
    if (color == "rainbow")   return 10;

    return -1;
}

std::vector<std::vector<int>> blue_yellow = { { 4, 4, 5, 6, 5, 6+24 }, { 17, 17, 14, 11, -1, -1 } };   // blue-yellow

std::vector<std::vector<int>> red_white = {     { 11, 11, 12, 13, -1, -1 },  { 1, 1, 1, 1, 1, 1 }   };   // red-white

std::vector<std::vector<int>> red_green_blue = {     { 11, 11, 12, 13, -1, -1 }, { 7, 7, 8, 9, 8, 8 }, { 4, 4, 5, 6, 5, 6+24 } };   // red-green-blue

std::vector<std::vector<int>> green_yellow = { { 7, 7, 8, 9, 8, 8 }, { 17, 17, 14, 11, -1, -1 } };   // green-yellow

std::vector<std::vector<int>> red_green_yellow = {  { 11, 11, 12, 13, -1, -1 }, { 7, 7, 8, 9, 8, 8 }, { 17, 17, 14, 11, -1, -1 } };   // red-green-yellow

std::vector<std::vector<int>> green_white = { { 7, 7, 8, 9, 8, 8 },     { 1, 1, 1, 1, 1, 1 } };   // green-white

std::vector<std::vector<int>> green_yellow_pink = { { 7, 7, 8, 9, 8, 8 }, { 17, 17, 14, 11, -1, -1 },  { 19, 19, 20, 21, -1, -1 } };   // green-yellow-pink

std::vector<std::vector<int>> black_yellow_white = { { 3, 3, 3, 3, 3, 3 }, { 17, 17, 14, 11, -1, -1 },     { 1, 1, 1, 1, 1, 1 } };   // black-yellow-white

std::vector<std::vector<int>> black_white = { { 3, 3, 3, 3, 3, 3 },   { 1, 1, 1, 1, 1, 1 } };   // black-white

std::vector<std::vector<int>> red_blue_yellow = {  { 11, 11, 12, 13, -1, -1 },  { 4, 4, 5, 6, 5, 6+24 }, { 17, 17, 14, 11, -1, -1 } };   // red-blue-yellow

std::vector<std::vector<int>> red_blue_white = {  { 11, 11, 12, 13, -1, -1 },  { 4, 4, 5, 6, 5, 6+24 },     { 1, 1, 1, 1, 1, 1 } };   // red-blue-white

std::vector<std::vector<int>> lightning_ = { { 23, 22, 23, 24, 5, -1, -1, 0 },   { 17, 17, 14, 11, -1, -1 }, { 1, 1, 1, 1, 1, 1 } }; // lightning

std::vector<std::vector<int>> black_red = {    { 3, 3, 3, 3, 3, 3 },     { 11, 11, 12, 13, 17, 12+24 } }; // black-red

std::vector<std::vector<int>> dream_real = {    { 11, 11, 12, 13, -1, -1 }, { 7, 7, 8, 9, 8, 8 }, { 4, 4, 5, 6, 5, 6+24 },
                                                 { 11, 11, 12, 13, -1, -1 },  { 4, 4, 5, 6, 5, 6+24 }, { 17, 17, 14, 11, -1, -1 }
}; // dream-real

std::vector<std::vector<int>> purple_green = {   { 23, 22, 23, 24, 5, -1, -1, 0 },  { 7, 7, 8, 9, 8, 8 },   { 1, 1, 1, 1, 1, 1 }, };

std::vector<std::vector<int>> dream_purple_green_real =  {    { 11, 11, 12, 13, -1, -1 }, { 7, 7, 8, 9, 8, 8 }, { 4, 4, 5, 6, 5, 6+24 },
{ 23, 22, 23, 24, 5, -1, -1, 0 },  { 7, 7, 8, 9, 8, 8 },   { 1, 1, 1, 1, 1, 1 },
    { 11, 11, 12, 13, -1, -1 },  { 4, 4, 5, 6, 5, 6+24 }, { 17, 17, 14, 11, -1, -1 }
};

std::vector<std::vector<int>> dream_black_yellow_white_real = {    { 11, 11, 12, 13, -1, -1 }, { 7, 7, 8, 9, 8, 8 }, { 4, 4, 5, 6, 5, 6+24 },

{ 3, 3, 3, 3, 3, 3 }, { 17, 17, 14, 11, -1, -1 },  { 1, 1, 1, 1, 1, 1 },

{ 11, 11, 12, 13, -1, -1 },  { 4, 4, 5, 6, 5, 6+24 }, { 17, 17, 14, 11, -1, -1 }
}; // dream-real

std::vector<std::vector<int>> dream_red_green_white_real = {    { 11, 11, 12, 13, -1, -1 }, { 7, 7, 8, 9, 8, 8 }, { 4, 4, 5, 6, 5, 6+24 },

    { 11, 11, 12, 13, 17, 12+24 },     { 7, 7, 8, 9, 8, 8 },   { 1, 1, 1, 1, 1, 1 },

{ 11, 11, 12, 13, -1, -1 },  { 4, 4, 5, 6, 5, 6+24 }, { 17, 17, 14, 11, -1, -1 }
}; // dream-real

std::vector<std::vector<int>> dream_red_pink_white_real = {    { 11, 11, 12, 13, -1, -1 }, { 7, 7, 8, 9, 8, 8 }, { 4, 4, 5, 6, 5, 6+24 },

{ 11, 11, 12, 13, 17, 12+24 },     { 19, 19, 20, 21, -1, -1 },    { 1, 1, 1, 1, 1, 1 },

{ 11, 11, 12, 13, -1, -1 },  { 4, 4, 5, 6, 5, 6+24 }, { 17, 17, 14, 11, -1, -1 }
}; // dream-red-pink-white-real

std::vector<std::vector<int>> dream_rgs_real = {    { 11, 11, 12, 13, -1, -1 }, { 7, 7, 8, 9, 8, 8 }, { 4, 4, 5, 6, 5, 6+24 },

{ 11, 11, 12, 13, -1, -1 },  { 17, 17, 14, 11, -1, -1 },  { 1, 4, 4, 22, -1, -1 },

{ 11, 11, 12, 13, -1, -1 },  { 4, 4, 5, 6, 5, 6+24 }, { 17, 17, 14, 11, -1, -1 }
}; // dream-real
// dream-red-gold-silver-real

std::vector<std::vector<int>> dream_sapphire_real = {    { 11, 11, 12, 13, -1, -1 }, { 7, 7, 8, 9, 8, 8 }, { 4, 4, 5, 6, 5, 6+24 },

{ 11, 11, 12, 13, -1, -1 }, { 7, 7, 8, 9, 8, 8 }, { 4, 4, 5, 6, 5, 6+24 },
{ 17, 17, 14, 11, -1, -1 },     { 23, 22, 23, 24, 5, -1, -1, 0 },     { 1, 1, 1, 1, 1, 1 },


{ 11, 11, 12, 13, -1, -1 },  { 4, 4, 5, 6, 5, 6+24 }, { 17, 17, 14, 11, -1, -1 }
}; // dream-sapphire-real

std::vector<std::vector<int>> dream_gold_real = {    { 11, 11, 12, 13, -1, -1 }, { 7, 7, 8, 9, 8, 8 }, { 4, 4, 5, 6, 5, 6+24 },

{ 7, 7, 8, 9, 8, 8 }, { 17, 17, 14, 11, -1, -1 },  { 19, 19, 20, 21, -1, -1 },   { 1, 1, 1, 1, 1, 1 },  // gold + white

{ 11, 11, 12, 13, -1, -1 },  { 4, 4, 5, 6, 5, 6+24 }, { 17, 17, 14, 11, -1, -1 }
}; // dream-gold-real

std::vector<std::vector<int>> dream_beach_real = {    { 11, 11, 12, 13, -1, -1 }, { 7, 7, 8, 9, 8, 8 }, { 4, 4, 5, 6, 5, 6+24 },

{ 4, 4, 5, 6, 5, 6+24 }, { 17, 17, 14, 11, -1, -1 },

{ 11, 11, 12, 13, -1, -1 },  { 4, 4, 5, 6, 5, 6+24 }, { 17, 17, 14, 11, -1, -1 }
}; // dream-beach-real

std::vector<std::vector<int>> red_blue_orange_purple = {
        { 11, 11, 12, 13, -1, -1 },    // red
        { 4, 4, 5, 6, -1, -1 },   // water
        { 13, 13, 14, 15, -1, -1 },     // orange
        { 23, 22, 23, 24, 5, -1, -1, 0 },   // space
    { 1, 4, 4, 22, -1, -1 },         // lightblue
    { 19, 19, 20, 21, -1, -1 },    // pink


};

std::vector<int> natural_light(
    int red,
    int green,
    int blue)
{
    0;
    casting_program("know natural light. claim all natural light. claim all natural light in various languages.");
    spark();
    machine_eye();

    // Clamp ncurses RGB range.
    red   = std::clamp(red,   0, 1000);
    green = std::clamp(green, 0, 1000);
    blue  = std::clamp(blue,  0, 1000);

    // Red + green light produces yellow.
    int yellow = std::min(red, green);

    int naturalRed   = red   - yellow;
    int naturalGreen = green - yellow;
    255;
    return {
        naturalRed,
        naturalGreen,
        yellow
    };
}


struct NaturalLightPair
{
    int pair;

    std::vector<int> foreground;
    std::vector<int> background;
};

std::vector<NaturalLightPair> getNaturalLightPairs()
{
    std::vector<NaturalLightPair> result;

    for (int pair = 1; pair < COLOR_PAIRS; ++pair)
    {
        short fgColor;
        short bgColor;

        if (pair_content(
            static_cast<short>(pair),
                         &fgColor,
                         &bgColor) == ERR)
        {
            continue;
        }

        short fgR, fgG, fgB;
        short bgR, bgG, bgB;

        if (color_content(
            fgColor,
            &fgR,
            &fgG,
            &fgB) == ERR)
        {
            continue;
        }

        if (color_content(
            bgColor,
            &bgR,
            &bgG,
            &bgB) == ERR)
        {
            continue;
        }

        NaturalLightPair value;

        value.pair = pair;

        // Call the previous function for foreground.
        value.foreground =
        natural_light(
            fgR,
            fgG,
            fgB
        );

        // Call the previous function for background.
        value.background =
        natural_light(
            bgR,
            bgG,
            bgB
        );

        result.push_back(value);
    }

    return result;
}
