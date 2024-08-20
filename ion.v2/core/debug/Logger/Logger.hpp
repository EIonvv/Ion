#pragma once

#include <iostream>

#include "../../resources/obfuscate.hpp"

class DebugLogger {

public:
    static bool LogDynamic(const std::string* message);
};