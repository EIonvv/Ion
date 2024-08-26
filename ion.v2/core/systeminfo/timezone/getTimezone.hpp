#pragma once

#include <chrono>
#include <iostream>

#include "../../resources/obfuscate.hpp"

class getTimezone : public std::string
{
public:
    static std::string Timezone();
};