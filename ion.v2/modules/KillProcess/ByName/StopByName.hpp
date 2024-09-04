#pragma once

#include <iostream>
#include <Windows.h>
#include <tlhelp32.h>
#include <string>
#include <cstdio>
#include <array>

#include "../../../core/CoreManager.hpp"
#include "../../../core/resources/obfuscate.hpp"
#include "../../../core/debug/Logger/Logger.hpp"

class StopByName
{
public:
    static void stop(const std::string *processName);
};