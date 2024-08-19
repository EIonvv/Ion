add_subdirectory(checks)
add_subdirectory(powershell)
add_subdirectory(removals)

target_sources(ion PRIVATE "Manager.cpp" "Manager.hpp")