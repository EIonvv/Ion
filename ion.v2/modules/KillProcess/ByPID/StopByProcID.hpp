#pragma once

#include <windows.h>
#include <fstream>
#include <string>
#include <thread>
#include <TlHelp32.h>

#include "../../../core/resources/obfuscate.hpp"
#include "../../../core/debug/Logger/Logger.hpp"

class StopByProcID
{
public:
    static DWORD stop(DWORD processID);
};