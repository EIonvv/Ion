#pragma once

#include <iostream>

#include "../../resources/obfuscate.hpp"

class DebugLogger
{

private:
    static std::string version;

public:
    static bool Info(const std::string *message, const char *functionName);
};