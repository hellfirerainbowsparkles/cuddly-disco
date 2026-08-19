PointCloud createDodecahedron(float size = 1.0f)
{
    PointCloud cloud;

    const float phi = (1.0f + std::sqrt(5.0f)) / 2.0f;
    const float invPhi = 1.0f / phi;
    const float s = size / phi;

    // 8 vertices: (±1, ±1, ±1)
    for (int x : {-1, 1})
        for (int y : {-1, 1})
            for (int z : {-1, 1})
                cloud.points.push_back({
                    x * s,
                    y * s,
                    z * s
                });

                // 4 vertices: (0, ±1/phi, ±phi)
                for (int y : {-1, 1})
                    for (int z : {-1, 1})
                        cloud.points.push_back({
                            0.0f,
                            y * invPhi * s,
                            z * phi * s
                        });

                        // 4 vertices: (±1/phi, ±phi, 0)
                        for (int x : {-1, 1})
                            for (int y : {-1, 1})
                                cloud.points.push_back({
                                    x * invPhi * s,
                                    y * phi * s,
                                    0.0f
                                });

                                // 4 vertices: (±phi, 0, ±1/phi)
                                for (int x : {-1, 1})
                                    for (int z : {-1, 1})
                                        cloud.points.push_back({
                                            x * phi * s,
                                            0.0f,
                                            z * invPhi * s
                                        });

                                        // Rotate so one pentagonal face is horizontal.
                                        // Face normal of the original dodecahedron:
                                        float nx = 0.0f;
                                        float ny = 1.0f;
                                        float nz = phi;

                                        float len = std::sqrt(nx * nx + ny * ny + nz * nz);

                                        nx /= len;
                                        ny /= len;
                                        nz /= len;

                                        // Rotate this normal onto the downward Y axis (0,-1,0).
                                        float tx = 0.0f;
                                        float ty = -1.0f;
                                        float tz = 0.0f;

                                        // rotation axis = n x target
                                        float ax = ny * tz - nz * ty;
                                        float ay = nz * tx - nx * tz;
                                        float az = nx * ty - ny * tx;

                                        float axisLen = std::sqrt(ax * ax + ay * ay + az * az);

                                        ax /= axisLen;
                                        ay /= axisLen;
                                        az /= axisLen;

                                        float dot = nx * tx + ny * ty + nz * tz;

                                        float angle = std::acos(dot);

                                        float c = std::cos(angle);
                                        float si = std::sin(angle);

                                        // Rodrigues rotation
                                        for (auto& p : cloud.points)
                                        {
                                            float x = p.x;
                                            float y = p.y;
                                            float z = p.z;

                                            float axisDot = ax * x + ay * y + az * z;

                                            float crossX = ay * z - az * y;
                                            float crossY = az * x - ax * z;
                                            float crossZ = ax * y - ay * x;

                                            p.x =
                                            x * c +
                                            crossX * si +
                                            ax * axisDot * (1.0f - c);

                                            p.y =
                                            y * c +
                                            crossY * si +
                                            ay * axisDot * (1.0f - c);

                                            p.z =
                                            z * c +
                                            crossZ * si +
                                            az * axisDot * (1.0f - c);
                                        }

                                        // Create edges
                                        const float edgeLength = 2.0f * invPhi * s;
                                        const float epsilon = 0.001f;

                                        for (int i = 0; i < (int)cloud.points.size(); ++i)
                                        {
                                            for (int j = i + 1; j < (int)cloud.points.size(); ++j)
                                            {
                                                float dx = cloud.points[i].x - cloud.points[j].x;
                                                float dy = cloud.points[i].y - cloud.points[j].y;
                                                float dz = cloud.points[i].z - cloud.points[j].z;

                                                float distance = std::sqrt(
                                                    dx * dx +
                                                    dy * dy +
                                                    dz * dz
                                                );

                                                if (std::abs(distance - edgeLength) < epsilon)
                                                    cloud.edges.push_back({i, j});
                                            }
                                        }

                                        return cloud;
}
