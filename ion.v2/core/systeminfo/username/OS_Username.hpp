#pragma once

#include <string>
#include <iostream>
#include <windows.h>
#include <lmcons.h>

class OS_Username : public std::string
{
public:
    static std::string GetUsername();
};