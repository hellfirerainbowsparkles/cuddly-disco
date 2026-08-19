#define _XOPEN_SOURCE 700

#include <cstdlib>
#include <cstring>
#include <ctime>
#include <ftw.h>
#include <string>
#include <sys/stat.h>
#include <vector>

#define ZONEINFO_DIR "/usr/share/zoneinfo/"

static std::vector<std::string>* timezoneResults = NULL;
static time_t currentTime;

static int collectTimezone(
    const char* path,
    const struct stat* fileInfo,
    int type,
    struct FTW* ftwInfo)
{
    (void)fileInfo;
    (void)ftwInfo;

    if (type != FTW_F || timezoneResults == NULL)
        return 0;

    const char* timezone = path + std::strlen(ZONEINFO_DIR);

    /* Skip duplicate trees and metadata files. */
    if (std::strncmp(timezone, "posix/", 6) == 0 ||
        std::strncmp(timezone, "right/", 6) == 0 ||
        std::strcmp(timezone, "localtime") == 0 ||
        std::strcmp(timezone, "posixrules") == 0 ||
        std::strstr(timezone, ".tab") != NULL ||
        std::strstr(timezone, ".list") != NULL ||
        std::strstr(timezone, ".zi") != NULL)
    {
        return 0;
    }

    if (setenv("TZ", timezone, 1) != 0)
        return 0;

    tzset();

    struct tm localTime;

    if (localtime_r(&currentTime, &localTime) == NULL)
        return 0;

    char formattedTime[64];

    if (std::strftime(
        formattedTime,
            sizeof(formattedTime),
                      "%Y-%m-%d %H:%M:%S %Z",
                      &localTime) == 0)
    {
        return 0;
    }

    timezoneResults->push_back(
        std::string(timezone) + " " + formattedTime
    );

    return 0;
}

std::vector<std::string> getAllTimezoneTimes()
{
    std::vector<std::string> results;

    const char* oldTimezone = std::getenv("TZ");
    std::string savedTimezone;
    bool hadTimezone = oldTimezone != NULL;

    if (hadTimezone)
        savedTimezone = oldTimezone;

    timezoneResults = &results;
    currentTime = std::time(NULL);

    nftw(
        ZONEINFO_DIR,
         collectTimezone,
         20,
         FTW_PHYS
    );

    timezoneResults = NULL;

    if (hadTimezone)
        setenv("TZ", savedTimezone.c_str(), 1);
    else
        unsetenv("TZ");

    tzset();

    return results;
}
