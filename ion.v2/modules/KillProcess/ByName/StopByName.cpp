#include "StopByName.hpp"
#include <cstdio>

#include <array>

void StopByName::stop(const std::string &processName)
{
    // Define an array of strings for the command parts
    std::array<std::string, 4> cmdParts = {
        "taskkill",
        "/F",
        "/IM",
        "\"" + processName + "\""};

    // Start building the command
    std::string cmd;
    bool firstPart = true;

    // Loop through the array and append each part to the command
    for (const auto &part : cmdParts)
    {
        if (firstPart)
        {
            cmd += part;
            firstPart = false;
        }
        else
        {
            cmd += " " + part;
        }
    }

    cmd += " > nul 2>&1";

    FILE *pipe = _popen(cmd.c_str(), "r");
    if (!pipe)
    {
        DebugLogger::LogDynamic(new const std::string(AY_OBFUSCATE("Failed to execute taskkill")));
        return;
    }

    char buffer[128];
    while (!feof(pipe))
    {
        if (fgets(buffer, 128, pipe) != NULL)
        {
            DebugLogger::LogDynamic(new const std::string(buffer));
        }
    }

    int result = _pclose(pipe);
    if (result == 0)
    {
        DebugLogger::LogDynamic(new const std::string(AY_OBFUSCATE("Successfully stopped process")));
    }
    else
    {
        DebugLogger::LogDynamic(new const std::string(AY_OBFUSCATE("Failed to stop process")));
    }
}