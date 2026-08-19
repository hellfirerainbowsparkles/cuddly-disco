// draw lines stored in higher order data structure than PointCloud which holds the information on which points should have lines drawn between them
// points: { { 9, 10 }, { 7, 6 }
// and so on. store entire data structure in .json file for every geometric structure.
// then add a drawing client to output the same structure, which draws in ncurses with a small editor for n amount of x z layers of n2xn2 size
// allow for one line of magic per structure as well

// also add a horizon .......

struct Polygon
{
    std::vector<int[2]> connections;
    std::string magic;
};
