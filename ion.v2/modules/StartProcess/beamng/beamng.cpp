#include "beamng.hpp"

int beamNG::StartBeamNG()
{

    Powershell::startPowershell(new const std::string(AY_OBFUSCATE("start steam://rungameid/284160")));
    return 0;
}