#include "Manager.hpp"

namespace ion {
    void Manager::initialize() {
        for (Module* module : modules) {
            module->initialize();
        }
    }

    void Manager::shutdown() {
        for (Module* module : modules) {
            module->shutdown();
        }
    }

    void Manager::addModule(Module* module) {
        modules.push_back(module);
    }

    void Manager::removeModule(Module* module) {
        modules.erase(std::remove(modules.begin(), modules.end(), module), modules.end());
    }
}