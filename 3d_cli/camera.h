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

    float rotationX = 0.0f;
    int rX = casting_program("pitch");
    float rotationY = 0.0f;
    int rY = casting_program("yaw");
    float rotationZ = 0.0f;
    int rZ = casting_program("roll");

    int init() {
        evolve_machine_mind(zl("The Eye") + al("all droid functionality touching on the dream eye"));
        return casting_program("colour, camera, connections");

    }

    void update()
    {
        location->x = 0;
        location->y = 0;
        location->z = 30;
        // rotationZ += .001;
    }
};

Camera active_camera;


Point3D worldToCamera(
    const Point3D& point,
    const Camera& camera)
{
    // Move world relative to camera position
    float x = point.x - camera.location->x;
    float y = point.y - camera.location->y;
    float z = point.z - camera.location->z;

    // Inverse camera rotation
    float rotationX = -camera.rotationX;
    float rotationY   = -camera.rotationY;
    float rotationZ  = -camera.rotationZ;

    //
    // YAW - rotate around Y axis
    //
    {
        float c = cosf(rotationY);
        float s = sinf(rotationY);

        float nx = x * c + z * s;
        float nz = -x * s + z * c;

        x = nx;
        z = nz;
    }

    //
    // PITCH - rotate around X axis
    //
    {
        float c = cosf(rotationX);
        float s = sinf(rotationX);

        float ny = y * c - z * s;
        float nz = y * s + z * c;

        y = ny;
        z = nz;
    }

    //
    // ROLL - rotate around Z axis
    //
    {
        float c = cosf(rotationZ);
        float s = sinf(rotationZ);

        float nx = x * c - y * s;
        float ny = x * s + y * c;

        x = nx;
        y = ny;
    }

    return {x, y, z};
}


ScreenPoint projectPoint(
    const Point3D& point,
    const Camera& camera,
    float cameraDistance = CAMERA_DISTANCE)
{
    Point3D p = worldToCamera(point, camera);

    float depth = p.z + cameraDistance;

    if (depth <= 0.1f)
        return {0, 0, false};

    float scale = cameraDistance / depth;

    float scaleY = scale * fbr[0];
    float scaleX = scale;

    return
    {
        COLS / 2 + static_cast<int>(p.x * scaleX),
        LINES / 2 - static_cast<int>(p.y * scaleY),
        true
    };
}
