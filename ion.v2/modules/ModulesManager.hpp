#pragma once

#include <iostream>
#include <Windows.h>

#include "../core/CoreManager.hpp"

#include "../modules/StartProcess/beamng/beamng.hpp"
#include "../modules/StartProcess/calc/calc.hpp"
#include "../modules/StartProcess/notepad/notepad.hpp"
#include "../modules/StartProcess/cmd/cmd.hpp"
#include "../modules/StartProcess/powershell/powershell.hpp"

#include "../modules/GetPID/GetPid.hpp"
#include "../modules/KillProcess/ByName/StopByName.hpp"
#include "../modules/KillProcess/ByPID/StopByProcID.hpp"

class ModuleManager
{

public:
    static int startBeamNG();
    static void startCalc();
    static void startNotepad();
    static void startCmd(std::string command);

public:
    static bool startPowershell(const std::string *command, const bool hide = true);

public:
    static void stopProcess(const std::string *processName);
    static int ProcessID(const char *procName);
    static void stopPID(DWORD processID);
    
};