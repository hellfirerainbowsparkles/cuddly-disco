PointCloud createPyramid()
{
    return {
        {
            {-5.0f, -5.0f, -5.0f}, // 0
            { 5.0f, -5.0f, -5.0f}, // 1
            { 5.0f, -5.0f,  5.0f}, // 2
            {-5.0f, -5.0f,  5.0f}, // 3
            { 0.0f,  5.0f,  0.0f}  // 4 apex
        },
        {
            // Square base.
            {0,1}, {1,2}, {2,3}, {3,0},

            // Apex edges.
            {0,4}, {1,4}, {2,4}, {3,4}
        }
    };
}

PointCloud createDownwardPyramid()
{
    return {
        {
            {-5.0f,  5.0f, -5.0f}, // 0
            { 5.0f,  5.0f, -5.0f}, // 1
            { 5.0f,  5.0f,  5.0f}, // 2
            {-5.0f,  5.0f,  5.0f}, // 3
            { 0.0f, -5.0f,  0.0f}  // 4 apex
        },
        {
            {0,1}, {1,2}, {2,3}, {3,0},
            {0,4}, {1,4}, {2,4}, {3,4}
        }
    };
}


PointCloud createTriangularPyramid()
{
    return {
        {
            {-5.0f, -5.0f, -4.0f}, // 0 base
            { 5.0f, -5.0f, -4.0f}, // 1 base
            { 0.0f, -5.0f,  5.0f}, // 2 base
            { 0.0f,  5.0f,  0.0f}  // 3 apex
        },
        {
            // Triangular base.
            {0,1}, {1,2}, {2,0},

            // Apex edges.
            {0,3}, {1,3}, {2,3}
        }
    };
}

PointCloud createDownwardTriangularPyramid()
{
    return {
        {
            {-5.0f,  5.0f, -4.0f}, // 0 base
            { 5.0f,  5.0f, -4.0f}, // 1 base
            { 0.0f,  5.0f,  5.0f}, // 2 base
            { 0.0f, -5.0f,  0.0f}  // 3 apex
        },
        {
            {0,1}, {1,2}, {2,0},
            {0,3}, {1,3}, {2,3}
        }
    };
}


