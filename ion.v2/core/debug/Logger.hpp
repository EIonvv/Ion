#pragma once

#include <iostream>

class DebugLogger {

public:
    static bool is_initialized;
public:
    static void LogDynamic(const std::string* message);
};