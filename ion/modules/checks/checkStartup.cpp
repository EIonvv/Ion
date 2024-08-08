#include "checkStartup.hpp"

void checkStartupFolder::checkFolder()
{
        // first get the path of the startup folder
    char* startupFolder = getenv("APPDATA");

    // check if the path is null
    if (startupFolder == NULL)
    {
        std::cerr << "Failed to get the path of the startup folder" << std::endl;
        return;
    }

    // create a string with the path of the startup folder
    std::string path = startupFolder;

    // append the name of the startup folder to the path
    path += "\\Microsoft\\Windows\\Start Menu\\Programs\\Startup";

    // create a handle to the directory
    HANDLE hFind;

    // create a WIN32_FIND_DATA structure to store information about the files in the directory
    WIN32_FIND_DATA data;

    // print details about all the files in the directory
    hFind = FindFirstFile((path + "\\*").c_str(), &data);

    // check if the handle is valid
    if (hFind == INVALID_HANDLE_VALUE)
    {
        std::cerr << "Failed to open directory" << std::endl;
        return;
    };

    // loop through all the files in the directory
    do
    {
        // print the name of the file
        std::cout << "Startup item: " << data.cFileName << std::endl;
    } while (FindNextFile(hFind, &data) != 0);

    // close the handle to the directory
    FindClose(hFind);

    return;
}
