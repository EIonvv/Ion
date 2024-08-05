#include "checkExclusions.hpp"

void checkExclusions::ExclusionCheck()
{
    std::string command = "powershell -Command \"Get-MpPreference | Select-Object -Property ExclusionExtension, ExclusionPath | Out-String -Width 4096\"";
    int result = system(command.c_str());

    if (result != 0)
    {
        std::cerr << "Failed to execute command" << std::endl;
    }
}
