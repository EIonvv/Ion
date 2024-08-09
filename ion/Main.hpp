#pragma once
#pragma comment(lib, "Ws2_32.lib")
#pragma comment(lib, "advapi32.lib")
#include "resources/obfuscate.hpp"

#include "modules/checks/network/checkArpTable.hpp"
#include "modules/checks/startup/checkStartup.hpp"
#include "modules/checks/startup/checkRegStartup.hpp"
#include "modules/checks/startup/checkTaskScheduler.hpp"
#include "modules/checks/windows_defender/checkExclusions.hpp"

#include "modules/removals/removeExclusion.hpp"
#include "my_c_functions.h"
