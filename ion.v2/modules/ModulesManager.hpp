#pragma once

#include <iostream>
#include <Windows.h>

#include "../modules/StartProcess/calc/calc.hpp"
#include "../modules/StartProcess/notepad/notepad.hpp"
#include "../modules/StartProcess/cmd/cmd.hpp"

#include "../modules/KillProcess/StopByName.hpp"

class ModuleManager
{
public:
    static void startCalc();
    static void startNotepad();
    static void startCmd(std::string command);
public:

    static void stopProcess(const std::string &processName);
};