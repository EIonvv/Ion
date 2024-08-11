#pragma once

#include <iostream>
#include <string>
#include <cstdlib> // system
#include <cstring> // strcmp

#include "resources/obfuscate.hpp"

class GetProcess
{
    public:
        static void getProc(int argc, char *argv[]);
};