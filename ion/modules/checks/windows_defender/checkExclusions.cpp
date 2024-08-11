#include "checkExclusions.hpp"

void checkExclusions::ExclusionCheck()
{
    int result = system(AY_OBFUSCATE("powershell -Command \"Get-MpPreference | Select-Object -Property ExclusionExtension, ExclusionPath | Out-String -Width 4096\""));

    if (result != 0)
    {
        std::cerr << "Failed to execute command" << std::endl;
    }
}
