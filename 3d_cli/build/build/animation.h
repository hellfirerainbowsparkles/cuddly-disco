#include <chrono>


class AnimationObject
{
public:
    float acceleration = 0.0f;
    float accelerationDecrease = (fbr[3]/10);
    float lifetime     = 1.0f;

    PointCloud object;

    // Rotation per axis
    float rotationX = 0.0f;
    float rotationY = 0.0f;
    float rotationZ = 0.0f;

    // Scale per axis
    float scaleX = 1.0f;
    float scaleY = 1.0f;
    float scaleZ = 1.0f;

    // colours for pointcloud
    std::vector<std::vector<int>> colours_collection =  { crystalcolours[5], crystalcolours[0], crystalcolours[1], crystalcolours[6], crystalcolours[2], crystalcolours[3] };

    float initialLifetime = lifetime;

    float initialRotationX;
    float initialRotationY;
    float initialRotationZ;

    float initialScaleX;
    float initialScaleY;
    float initialScaleZ;

    bool running   = false;
    bool destroyed = false;
    bool drawLines = true;

private:
    std::chrono::steady_clock::time_point lastUpdate;

public:

    AnimationObject(
        const PointCloud& pointCloud,
        float lifetimeSeconds = 1.0f,
        float accelerationValue = 1.0f)
    :
    acceleration(accelerationValue),
    lifetime(lifetimeSeconds),
    object(pointCloud)
    {


    }


    void start()
    {
        running = true;
        destroyed = false;


        initialLifetime = lifetime;

        initialRotationX = rotationX;
        initialRotationY = rotationY;
        initialRotationZ = rotationZ;

        initialScaleX = scaleX;
        initialScaleY = scaleY;
        initialScaleZ = scaleZ;

        lastUpdate =
        std::chrono::steady_clock::now();
    }


    void setDrawLines(bool dl) {
        drawLines = dl;
    }

    int objectIndex = 0;

    // -----------------------------------------
    // Rotation setter
    // -----------------------------------------

    void setRotation(
        float x,
        float y,
        float z)
    {
        rotationX = x;
        rotationY = y;
        rotationZ = z;
    }


    // -----------------------------------------
    // Scale setter
    // -----------------------------------------

    void setScale(
        float x,
        float y,
        float z)
    {
        scaleX = x;
        scaleY = y;
        scaleZ = z;
    }


    void setAcceleration(float value)
    {
        acceleration = value;
    }

    void setAccelerationDecrease(float value)
    {
        accelerationDecrease = value;
    }


    void setLifetime(float value)
    {
        lifetime = value;
    }


    void setObject(const PointCloud& newObject)
    {
        object = newObject;
    }


    void run(PointCloud& newObject)
    {
        if (!running || destroyed)
            return;

        auto now =
        std::chrono::steady_clock::now();

        float deltaTime =
        std::chrono::duration<float>(
            now - lastUpdate
        ).count();

        lastUpdate = now;


        // -----------------------------------------
        // Lifetime
        // -----------------------------------------

        lifetime -= deltaTime;

        if (lifetime <= 0.0f)
        {
            destroy();
            return;
        }

        // -----------------------------------------
        // Acceleration affects rotation and scale
        // -----------------------------------------

        if (rotationX > 0 || rotationZ > 0 || rotationY > 0) {
            rotationX += acceleration * deltaTime;
            rotationY += acceleration * deltaTime;
            rotationZ += acceleration * deltaTime;
        }

        if (scaleX > 0 || scaleY > 0 || scaleZ > 0) {
            scaleX += acceleration * deltaTime;
            scaleY += acceleration * deltaTime;
            scaleZ += acceleration * deltaTime;
        }

        // reduce acceleration
        if (acceleration > 0 && accelerationDecrease > 0.00618) {
            acceleration -= accelerationDecrease;
            accelerationDecrease -= (fbr[0]/100);
        }
        // -----------------------------------------
        // Create transformed frame
        // -----------------------------------------

        // Scale independently on X/Y/Z.
        newObject.scaleX += scaleX;
        newObject.scaleY += scaleY;
        newObject.scaleZ += scaleZ;


    }


    void destroy()
    {
        running = false;
        destroyed = true;
        reset();
    }


    bool isAlive() const
    {
        return !destroyed;
    }


    float getLifetime() const
    {
        return lifetime;
    }

    void reset()
    {
        running = false;
        destroyed = false;

        lifetime = initialLifetime;

        rotationX = initialRotationX;
        rotationY = initialRotationY;
        rotationZ = initialRotationZ;

        scaleX = initialScaleX;
        scaleY = initialScaleY;
        scaleZ = initialScaleZ;

        object.reset();
    }


    ~AnimationObject()
    {
        destroy();
    }
};
