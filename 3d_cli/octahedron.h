PointCloud createOctahedron()
{
    return {
        {
            { 0.0f,  5.0f,  0.0f}, // 0 top
            { 0.0f, -5.0f,  0.0f}, // 1 bottom
            {-5.0f,  0.0f,  0.0f}, // 2 left
            { 5.0f,  0.0f,  0.0f}, // 3 right
            { 0.0f,  0.0f, -5.0f}, // 4 back
            { 0.0f,  0.0f,  5.0f}  // 5 front
        },
        {
            // Equatorial square.
            {2,4}, {4,3}, {3,5}, {5,2},

            // Top edges.
            {0,2}, {0,3}, {0,4}, {0,5},

            // Bottom edges.
            {1,2}, {1,3}, {1,4}, {1,5}
        }
    };
}
