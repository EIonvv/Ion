#pragma once

#include "core.hpp"

namespace ion {
    class Module {
    public:
        virtual void initialize() = 0;
        virtual void shutdown() = 0;
    };
}