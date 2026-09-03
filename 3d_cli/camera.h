static const float CAMERA_DISTANCE = 150.0f;
static const float CAMERA_DISTANCE_TO_RENDER = CAMERA_DISTANCE; //190.0f;




struct ScreenPoint
{
    int x;
    int y;
    bool visible;
};


struct Camera
{
    Point3D* location = new Point3D();
    Point3D centerFocus;

    float rotationX = 0.0f;
    int rX = casting_program("pitch");
    float rotationY = 0.0f;
    int rY = casting_program("yaw");
    float rotationZ = 0.0f;
    int rZ = casting_program("roll");

    bool rotateAroundCamera = false;

    int init(Point3D center_focus =  Point3D{0.0f, 0.0f, 0.0f}) {
        evolve_machine_mind(zl("The Eye") + al("all droid functionality touching on the dream eye"));
        return casting_program("colour, camera, connections");

            location->x = 0.0f;
            location->y = 10.0f;
            location->z = 10.0f;

            centerFocus = {
                0.0f,
                0.0f,
                0.0f
            };

            this->centerFocus = center_focus;

            alignToCenterFocus();

    }


    Point3D calculateCenterFocus(
        float distance = 1.0f)
    {
        // Camera forward direction before rotation.
        float x = 0.0f;
        float y = 0.0f;
        float z = 1.0f;

        float rx = rotationX;
        float ry = rotationY;
        float rz = rotationZ;

        // Inverse of worldToCamera rotation order:
        // Roll
        {
            float c = cosf(rz);
            float s = sinf(rz);

            float nx = x * c - y * s;
            float ny = x * s + y * c;

            x = nx;
            y = ny;
        }

        // Pitch
        {
            float c = cosf(rx);
            float s = sinf(rx);

            float ny = y * c - z * s;
            float nz = y * s + z * c;

            y = ny;
            z = nz;
        }

        // Yaw
        {
            float c = cosf(ry);
            float s = sinf(ry);

            float nx = x * c + z * s;
            float nz = -x * s + z * c;

            x = nx;
            z = nz;
        }

        return {
            location->x + x * distance,
            location->y + y * distance,
            location->z + z * distance
        };
    }


    void alignToCenterFocus()
    {
        float dx = centerFocus.x - location->x;
        float dy = centerFocus.y - location->y;
        float dz = centerFocus.z - location->z;

        float horizontalLength =
        sqrtf(dx * dx + dz * dz);

        rotationY =
        atan2f(dx, dz);

        rotationX =
        -atan2f(dy, horizontalLength);

        rotationZ = 0.0f;
    }

    void update()
    {
        this->centerFocus = calculateCenterFocus();
        alignToCenterFocus();
    }
};

Camera active_camera;

Point3D worldToCamera(
    const Point3D& point,
    const Camera& camera)
{
    float x;
    float y;
    float z;

    if (camera.rotateAroundCamera)
    {
        // Camera position is the rotation pivot.
        x = point.x - camera.location->x - CAMERA_DISTANCE;
        y = point.y - camera.location->y - CAMERA_DISTANCE;
        z = point.z - camera.location->z - CAMERA_DISTANCE;
    }
    else
    {
        // World origin is the rotation pivot.
        x = point.x;
        y = point.y;
        z = point.z;
    }

    float rx = -camera.rotationX;
    float ry = -camera.rotationY;
    float rz = -camera.rotationZ;

    // YAW
    {
        float c = cosf(ry);
        float s = sinf(ry);

        float nx = x * c + z * s;
        float nz = -x * s + z * c;

        x = nx;
        z = nz;
    }

    // PITCH
    {
        float c = cosf(rx);
        float s = sinf(rx);

        float ny = y * c - z * s;
        float nz = y * s + z * c;

        y = ny;
        z = nz;
    }

    // ROLL
    {
        float c = cosf(rz);
        float s = sinf(rz);

        float nx = x * c - y * s;
        float ny = x * s + y * c;

        x = nx;
        y = ny;
    }

    if (!camera.rotateAroundCamera)
    {
        x -= camera.location->x;
        y -= camera.location->y;
        z -= camera.location->z;
    }

    return {x, y, z};
}


ScreenPoint projectPoint(
    const Point3D& point,
    const Camera& camera,
    float cameraDistance = CAMERA_DISTANCE)
{
    Point3D p = worldToCamera(
        point,
        camera
    );

    float depth = p.z + cameraDistance;

    if (depth <= 0.1f)
        return {0, 0, false};

    float scale = cameraDistance / depth;

    float scaleX = scale;
    float scaleY = scale * fbr[0];

    return
    {
        COLS / 2 + static_cast<int>(p.x * scaleX),
        LINES / 2 - static_cast<int>(p.y * scaleY),
        true
    };
}

void moveCameraForward(
    Camera& camera,
    float amount)
{
    float dx = camera.centerFocus.x - camera.location->x;
    float dy = camera.centerFocus.y - camera.location->y;
    float dz = camera.centerFocus.z - camera.location->z;

    float length = sqrtf(
        dx * dx +
        dy * dy +
        dz * dz
    );

    if (length <= 0.0001f)
        return;

    // Normalize direction.
    dx /= length;
    dy /= length;
    dz /= length;

    // Move camera along vector.
    camera.location->x += dx * amount;
    camera.location->y += dy * amount;
    camera.location->z += dz * amount;
}


std::vector<Face> getCameraFacingFaces(
    const PointCloud& pointcloud,
    const Camera& camera)
{
    std::vector<Face> visibleFaces;

    for (const Face& face : pointcloud.faces)
    {
        if (face.points.size() < 3)
            continue;

        const Point3D& a =
        pointcloud.points[face.points[0]];

        const Point3D& b =
        pointcloud.points[face.points[1]];

        const Point3D& c =
        pointcloud.points[face.points[2]];

        Point3D ab = {
            b.x - a.x,
            b.y - a.y,
            b.z - a.z
        };

        Point3D ac = {
            c.x - a.x,
            c.y - a.y,
            c.z - a.z
        };

        Point3D normal = {
            ab.y * ac.z - ab.z * ac.y,
            ab.z * ac.x - ab.x * ac.z,
            ab.x * ac.y - ab.y * ac.x
        };

        Point3D toCamera = {
            camera.location->x - a.x,
            camera.location->y - a.y,
            camera.location->z - a.z
        };

        float dot =
        normal.x * toCamera.x +
        normal.y * toCamera.y +
        normal.z * toCamera.z;

        if (dot > 0.0f)
            visibleFaces.push_back(face);
    }

    return visibleFaces;
}
