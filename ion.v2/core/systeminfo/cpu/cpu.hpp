#include <iostream>
#include <vector>
#include <array>
#include <Windows.h>

#include "../../resources/obfuscate.hpp"

class cpu : public std::string
{
public:
    static std::string GetCpuInfo();
};