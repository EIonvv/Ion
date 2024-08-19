#pragma once

#include "../core/core.hpp"
#include "../core/Module.hpp"

namespace ion {
    class Manager {
    public:
        void initialize();
        void shutdown();
        void addModule(Module* module);
        void removeModule(Module* module);
    private:
        std::vector<Module*> modules;
    };
}