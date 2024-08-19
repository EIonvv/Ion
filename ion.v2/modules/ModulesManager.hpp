#pragma once

#include <iostream>
#include <Windows.h>

#include "../modules/StartProcess/calc.hpp"
#include "../modules/KillProcess/StopByName.hpp"

class ModuleManager
{
public:
    static void startCalc();
    static void stopProcess(const std::string &processName);
};