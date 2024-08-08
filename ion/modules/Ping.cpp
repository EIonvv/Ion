#include "Ping.hpp"

void Ping::pingHost(char *host)
{
    // Construct the ping command string
    char cmd[256] = "ping -n 4 "; // -n specifies the number of echo requests to send
    strcat(cmd, host);       // Append the IP address to the command

    // Execute the ping command
    system(cmd);

    // Optionally, wait for the user to press Enter before closing the console window
    // printf("\nPress Enter to exit...");
    // getchar();
}