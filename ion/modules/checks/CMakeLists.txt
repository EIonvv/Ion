target_sources(ion PRIVATE
  "network/checkArpTable.cpp"
  "network/checkArpTable.hpp"
  "startup/checkRegStartup.cpp"
  "startup/checkRegStartup.hpp"
  "startup/checkStartup.cpp"
  "startup/checkStartup.hpp"
  "startup/checkTaskScheduler.cpp"
  "startup/checkTaskScheduler.hpp"
  "windows_defender/checkExclusions.cpp"
  "windows_defender/checkExclusions.hpp"
)

add_subdirectory(windows_defender)