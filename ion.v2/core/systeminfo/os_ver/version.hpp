#pragma once 

#include <iostream>
#include <Windows.h>
#include <string>
#include "../../resources/obfuscate.hpp"

class Version
{
public:
    static std::string GetOSVersion();
};