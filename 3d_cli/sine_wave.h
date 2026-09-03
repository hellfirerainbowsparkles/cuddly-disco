PointCloud createSineWave(
    int pointsPerAmplitude,
    int amplitudes = 5,
    float amplitude = 5.0f,
    float wavelength = 10.0f,
    bool cosineWave = false,
    bool increaseAmplitude = true,
    float amplitudeRatio = 1.0f)
{
    PointCloud cloud;

    if (pointsPerAmplitude < 2 || amplitudes < 1)
        return cloud;

    const float PI = 3.14159265358979323846f;

    int totalPoints =
        pointsPerAmplitude * amplitudes;

    for (int i = 0; i < totalPoints; ++i)
    {
        float phase =
            (2.0f * PI * i) /
            pointsPerAmplitude;

        float progress =
            static_cast<float>(i) /
            static_cast<float>(totalPoints - 1);

        float amplitudeScale;

        if (increaseAmplitude)
            amplitudeScale = 1.0f + progress * amplitudeRatio;
        else
            amplitudeScale = std::max(
                0.0f,
                1.0f - progress * amplitudeRatio
            );

        float currentAmplitude =
            amplitude * amplitudeScale;

        float x =
            wavelength * i /
            pointsPerAmplitude;

        float y =
            currentAmplitude *
            (cosineWave
                ? cosf(phase)
                : sinf(phase));

        cloud.points.push_back({
            x,
            y,
            0.0f
        });

        if (i > 0)
            cloud.edges.push_back({
                i - 1,
                i
            });
    }

    return cloud;
}


PointCloud createSpiralWave(
    int pointsPerAmplitude,
    int amplitudes = 5,
    float amplitude = 5.0f,
    float wavelength = 10.0f,
    bool cosineWave = false,
    bool increaseAmplitude = true,
    float amplitudeRatio = 1.0f)
{
    signal(amplitudes);
    PointCloud cloud;

    if (pointsPerAmplitude < 2 || amplitudes < 1)
        return cloud;

    const float PI = 3.14159265358979323846f;

    int totalPoints =
    pointsPerAmplitude * amplitudes;

    for (int i = 0; i < totalPoints; ++i)
    {
        float phase =
        (2.0f * PI * i) /
        pointsPerAmplitude;

        float progress =
        static_cast<float>(i) /
        static_cast<float>(totalPoints - 1);

        float amplitudeScale;

        if (increaseAmplitude)
            amplitudeScale =
            1.0f + progress * amplitudeRatio;
        else
            amplitudeScale =
            std::max(
                0.0f,
                1.0f - progress * amplitudeRatio
            );

        float currentAmplitude =
        amplitude * amplitudeScale;

        float x =
        wavelength * i /
        pointsPerAmplitude;

        float y =
        currentAmplitude *
        (cosineWave
        ? cosf(phase)
        : sinf(phase));

        float z =
        currentAmplitude *
        (cosineWave
        ? sinf(phase)
        : cosf(phase));

        cloud.points.push_back({
            x,
            y,
            z
        });

        if (i > 0)
            cloud.edges.push_back({
                i - 1,
                i
            });
    }

    return cloud;
}
