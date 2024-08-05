#include "Main.hpp"

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

void PingIP(char *ipAddress)
{
    // Construct the ping command string
    char cmd[256] = "ping -n 4 "; // -n specifies the number of echo requests to send
    strcat(cmd, ipAddress);       // Append the IP address to the command

    // Execute the ping command
    system(cmd);

    // Optionally, wait for the user to press Enter before closing the console window
    // printf("\nPress Enter to exit...");
    // getchar();
}

// my_c_functions.h
#ifdef __cplusplus
extern "C"
{
#endif

    void my_c_function(); // Declare your C function

#ifdef __cplusplus
}
#endif

void my_c_function()
{
    // print hello in C
    std::string hello = "Hello from C!";
    printf("%s\n", hello.c_str());
}

int main(int argc, char *argv[])
{

    my_c_function(); // Call your C function
    // write what command was executed and save to a file
    FILE *file = fopen("log.txt", "a");

    if (file == NULL)
    {
        printf("Error opening file!\n");
        return 1;
    }

    // parameters
    fprintf(file, "{Command: '%s', Parameter: '%s'}\n", argv[1], argv[2] ? argv[2] : "NULL");
    fclose(file);

    // check if it has / before the command
    if (argc < 2 || argv[1][0] != '/')
    {
        printf("Invalid command try /?\n");
        return 1;
    }

    if (strcmp(argv[1], "/get") == 0)
    {
        // Clear screen
        system("cls");
        for (int i = 0; i < atoi(argv[4] ? argv[4] : "1"); i++)
        {
            GetInfo(argc, argv);
        }
    }
    else if (strcmp(argv[1], "/ping") == 0)
    {
        // Clear screen
        system("cls");
        PingIP(argv[2]);
        return 0;
    }
    else if (strcmp(argv[1], "/arp") == 0)
    {
        // Clear screen
        system("cls");
        CheckArpTable::checkTable();
        return 0;
    }
    else if (strcmp(argv[1], "/exclusions") == 0)
    {
        // Clear screen
        system("cls");
        checkExclusions::ExclusionCheck();
        return 0;
    }
    else if (strcmp(argv[1], "/removeExclusion") == 0)
    {
        // Clear screen
        system("cls");
        removeExclusion::removePath(argc, argv);
        return 0;
    }
    else if (
        strcmp(argv[1], "/?") == 0 ||
        strcmp(argv[1], "/h") == 0)
    {
        system("cls");

        // debug print the arguments
        // for (int i = 0; i < argc; i++)
        // {
        // printf("argv[%d] = %s\n", i, argv[i]);
        // }

        // print the prefix
        printf("\033[1;34mIon\033[0m: A simple network utility\n");
        printf("\033[1;31mPrefix\033[0m: /\n");
        printf("  Usage: %s <command> <URL or IP>\n", argv[0]);

        printf("  \nNetwork Related:\n");
        printf("  \033[1;31mget\033[0m   - Retrieve information from a website\n");
        printf("  \033[1;31mping\033[0m  - Ping an IP address\n");
        printf("  \033[1;31marp\033[0m   - Display ARP table\n");

        printf("  \nWindows Defender Related:\n");
        printf("  \033[1;31mexclusions\033[0m - Display Windows Defender exclusions\n");
        printf("  \033[1;31mremoveExclusion\033[0m - Remove a Windows Defender exclusion\n");
        printf("  \n");
        return 0;
    }
    else
    {
        printf("Invalid command\n");
        return 1;
    }

    return 0;
}
