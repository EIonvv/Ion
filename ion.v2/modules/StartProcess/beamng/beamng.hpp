#pragma once

#include <string>
#include <iostream>
#include <Windows.h>

#include "../../../core/CoreManager.hpp"
#include "../../../core/resources/obfuscate.hpp"
#include "../../../modules/StartProcess/powershell/powershell.hpp"

class beamNG
{

public:
    static int StartBeamNG();
    static int StartBeamMP();
};
