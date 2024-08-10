#include "my_c_functions.h"
#include "Main.hpp"

extern "C"
{
    char *UserName()
    {
        char name[100];

        // Find the user name in the environment
        if (getenv("USERNAME") != NULL)
        {
            strncpy(name, getenv("USERNAME"), sizeof(name));
        }
        else
        {
            strncpy(name, "User", sizeof(name));
        }

        // Allocate memory for the return string
        size_t len = strlen(name);
        char *result = new char[len + 1]; // Allocate enough space for the null terminator
        strcpy(result, name);

        return result;
    }
}
int GetInfo(int argc, char *argv[])
{
    WSADATA wsaData;
    int result = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (result != 0)
    {
        printf("WSAStartup failed: %d\n", result);
        return 1;
    }

    SOCKET clientSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (clientSocket == INVALID_SOCKET)
    {
        printf("socket failed with error: %d\n", WSAGetLastError());
        WSACleanup();
        return 1;
    }

    sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(atoi(argv[3]));

    // Check if the second argument is an IP address
    if (inet_pton(AF_INET, argv[2], &serverAddress.sin_addr) <= 0)
    {
        // Assume it's a hostname
        struct hostent *host_info = gethostbyname(argv[2]);
        if (!host_info || !host_info->h_addr_list)
        {
            printf("Could not resolve hostname\n");
            closesocket(clientSocket);
            WSACleanup();
            return 1;
        }
        memcpy(&serverAddress.sin_addr, host_info->h_addr_list[0], host_info->h_length);
    }

    if (connect(clientSocket, (struct sockaddr *)&serverAddress, sizeof(serverAddress)) == SOCKET_ERROR)
    {
        printf("connect failed with error: %d\n", WSAGetLastError());
        closesocket(clientSocket);
        WSACleanup();
        return 1;
    }

    // Construct HTTP GET request
    char request[1024] = "GET / HTTP/1.1\r\nHost: ";
    strcat(request, argv[2]); // Use the provided URL or IP
    strcat(request, "\r\nConnection: close\r\n\r\n");

    // Send request
    send(clientSocket, request, strlen(request), 0);

    // Receive response
    char buffer[4096] = {0};
    int bytesReceived = recv(clientSocket, buffer, sizeof(buffer), 0);
    if (bytesReceived > 0)
    {
        printf("%.*s\n", bytesReceived, buffer); // Print the received response
    }
    else
    {
        printf("Failed to receive response\n");
    }

    closesocket(clientSocket);
    WSACleanup();

    return 0;
}

int main(int argc, char *argv[])
{

    // write what command was executed and save to a file
    // FILE *file = fopen("log.txt", "a");

    // if (file == NULL)
    // {
    //     printf("Error opening file!\n");
    //     return 1;
    // }

    // // parameters
    // fprintf(file, "{Command: '%s', Parameter: '%s'}\n", argv[1], argv[2] ? argv[2] : "NULL");
    // fclose(file);

    // check if it has / before the command
    if (argc < 2 || argv[1][0] != '/')
    {
        printf("Invalid command try /?\n");
        return 1;
    }

    if (strcmp(argv[1], AY_OBFUSCATE("/get")) == 0)
    {
        // Clear screen
        system("cls");
        for (int i = 0; i < atoi(argv[4] ? argv[4] : "1"); i++)
        {
            GetInfo(argc, argv);
        }
        return 0;
    }
    else if (strcmp(argv[1], AY_OBFUSCATE("/ping")) == 0)
    {
        // Not implemented
    }
    else if (strcmp(argv[1], AY_OBFUSCATE("/arp")) == 0)
    {
        // Clear screen
        system("cls");
        CheckArpTable::checkTable();
        return 0;
    }
    else if (strcmp(argv[1], AY_OBFUSCATE("/env")) == 0)
    {
        // Clear screen
        system("cls");
        checkEnvVariables::CheckVariables();
        return 0;
    }
    else if (strcmp(argv[1], AY_OBFUSCATE("/startupcheck_folder")) == 0)
    {
        checkStartupFolder::checkFolder();
        return 0;
    }
    else if (strcmp(argv[1], AY_OBFUSCATE("/startupcheck_registry")) == 0)
    {
        checkRegStartup::checkRegStartUp();
        return 0;
    }
    else if (strcmp(argv[1], AY_OBFUSCATE("/taskcheck")) == 0)
    {
        checkTaskScheduler::check();
        return 0;
    }
    else if (strcmp(argv[1], AY_OBFUSCATE("/exclusions")) == 0)
    {
        // Clear screen
        system("cls");
        checkExclusions::ExclusionCheck();
        return 0;
    }
    else if (strcmp(argv[1], AY_OBFUSCATE("/removeExclusionPath")) == 0)
    {
        // Clear screen
        system("cls");
        removeExclusion::removePath(argc, argv);
        return 0;
    }
    else if (strcmp(argv[1], AY_OBFUSCATE("/removeExclusionExtension")) == 0)
    {
        // Clear screen
        system("cls");
        removeExclusion::removeExtension(argc, argv);
        return 0;
    }
    else if (
        strcmp(argv[1], AY_OBFUSCATE("/?")) == 0 ||
        strcmp(argv[1], AY_OBFUSCATE("/h")) == 0 ||
        strcmp(argv[1], AY_OBFUSCATE("?")) == 0)
    {
        system("cls");

        // debug print the arguments
        // for (int i = 0; i < argc; i++)
        // {
        // printf("argv[%d] = %s\n", i, argv[i]);
        // }

        // print the prefix
        printf(AY_OBFUSCATE("\033[1;34mHello\033[0m, %s!\n"), UserName());
        printf(AY_OBFUSCATE("\033[1;34mUsage\033[0m: %s /<command> <URL or IP>\n"), argv[0]);

        printf(AY_OBFUSCATE("  \nNetwork:\n"));
        printf(AY_OBFUSCATE("  \033[1;31mget\033[0m   - Retrieve information from a website\n"));
        printf(AY_OBFUSCATE("  \033[1;31marp\033[0m   - Display ARP table\n"));
        printf(AY_OBFUSCATE("  \033[1;31mping\033[0m  - Ping an IP address\n"));

        printf(AY_OBFUSCATE("  \nWindows Defender:\n"));
        printf(AY_OBFUSCATE("  \033[1;31mexclusions\033[0m - Display Windows Defender exclusions\n"));
        printf(AY_OBFUSCATE("  \033[1;31mremoveExclusionPath\033[0m - Remove Windows Defender exclusion by path\n"));
        printf(AY_OBFUSCATE("  \033[1;31mremoveExclusionExtension\033[0m - Remove Windows Defender exclusion by extension\n"));

        printf(AY_OBFUSCATE("  \nStartup:\n"));
        printf(AY_OBFUSCATE("  \033[1;31mtaskcheck\033[0m - Check Task Scheduler\n"));
        printf(AY_OBFUSCATE("  \033[1;31mstartupcheck_folder\033[0m - Check startup programs in the startup folder\n"));
        printf(AY_OBFUSCATE("  \033[1;31mstartupcheck_registry\033[0m - Check startup programs in the registry\n"));

        printf(AY_OBFUSCATE("  \nEnvironment:\n"));
        printf(AY_OBFUSCATE("  \033[1;31menv\033[0m   - Display environment variables\n"));

        printf(AY_OBFUSCATE("  \n"));
        return 0;
    }
    else
    {
        printf("Invalid command\n");
        return 1;
    };

    return 0;
};
