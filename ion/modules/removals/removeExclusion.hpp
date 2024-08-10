#pragma once

#include <cstdlib> // For std::system
#include <iostream>
#include "../../resources/obfuscate.hpp"
class removeExclusion
{
public:
    static void removePath(int argc, char *argv[]);
    static void removeExtension(int argc, char *argv[]);
};