add_subdirectory(KillProcess)
add_subdirectory(PID)
add_subdirectory(StartProcess)

target_sources(
    ion 
    PRIVATE 
    "ModulesManager.cpp"
)