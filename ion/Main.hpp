#pragma once
#pragma comment(lib, "Ws2_32.lib")
#pragma comment(lib, "advapi32.lib")

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "core/info/osUsername.h"

#include "modules/checks/environment/checkEnvVariables.hpp"
#include "modules/checks/network/checkArpTable.hpp"
#include "modules/checks/startup/checkStartup.hpp"
#include "modules/checks/startup/checkRegStartup.hpp"
#include "modules/checks/startup/checkTaskScheduler.hpp"
#include "modules/checks/windows_defender/checkExclusions.hpp"

#include "modules/powershell/GetProcess.hpp"
#include "modules/powershell/KillProcess.hpp"

#include "modules/removals/removeExclusion.hpp"
#include "resources/obfuscate.hpp"
