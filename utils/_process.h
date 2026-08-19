#include <cstdlib>
#include <string>

class BackgroundProcess
{
private:
    std::string command;
    std::string processName;

public:
    BackgroundProcess(const std::string& cmd,
                      const std::string& name)
        : command(cmd), processName(name)
    {
    }

    void run()
    {
        std::string cmd ="screen "+ command + " > /dev/null 2>&1 &";
        system(cmd.c_str());
    }

    void kill()
    {
        std::string cmd = "pkill -f '" + processName + "'";
        system(cmd.c_str());
    }

    void restart()
    {
        kill();
        run();
    }

    bool isRunning()
    {
        std::string cmd =
            "pgrep -f '" + processName + "' > /dev/null";

        return system(cmd.c_str()) == 0;
    }
};
