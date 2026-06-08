#include <iostream>
#include <cstdlib>
#include <unistd.h>

using namespace std;

// COLORS
#define GREEN "\033[1;32m"
#define RED "\033[1;31m"
#define CYAN "\033[1;36m"
#define YELLOW "\033[1;33m"
#define RESET "\033[0m"

void banner() {
    cout << CYAN << R"(
██╗     ██╗   ██╗██╗  ██╗ █████╗ 
██║     ██║   ██║██║  ██║██╔══██╗
██║     ██║   ██║███████║███████║
██║     ██║   ██║██╔══██║██╔══██║
███████╗╚██████╔╝██║  ██║██║  ██║
╚══════╝ ╚═════╝ ╚═╝  ╚═╝╚═╝  ╚═╝

   LUXA CYBER TOOL v4
   Advanced Security Dashboard
)" << RESET << endl;
}

void systemInfo() {
    cout << GREEN << "\n[ SYSTEM INFO ]\n" << RESET;
    system("uname -a");
    system("whoami");
}

void networkInfo() {
    cout << YELLOW << "\n[ NETWORK INFO ]\n" << RESET;
    system("hostname");
    system("ip a | head -n 10");
}

void fileScan() {
    cout << CYAN << "\n[ FILE SYSTEM ]\n" << RESET;
    system("ls -lah");
}

void processView() {
    cout << GREEN << "\n[ PROCESSES ]\n" << RESET;
    system("ps aux | head -n 15");
}

void memoryInfo() {
    cout << YELLOW << "\n[ MEMORY INFO ]\n" << RESET;
    system("free -h");
}

void safePortCheck() {
    cout << RED << "\n[ LOCAL PORT CHECK (SAFE) ]\n" << RESET;
    system("ss -tuln | head -n 15");
}

int main() {
    int choice;

    banner();

    while (true) {
        cout << CYAN << "\n====== LUXA v4 MENU ======\n" << RESET;
        cout << "1. System Info\n";
        cout << "2. Network Info\n";
        cout << "3. File System\n";
        cout << "4. Process Viewer\n";
        cout << "5. Memory Info\n";
        cout << "6. Local Port Check\n";
        cout << "7. Exit\n";
        cout << "Select: ";

        cin >> choice;

        switch(choice) {
            case 1: systemInfo(); break;
            case 2: networkInfo(); break;
            case 3: fileScan(); break;
            case 4: processView(); break;
            case 5: memoryInfo(); break;
            case 6: safePortCheck(); break;
            case 7:
                cout << "Exiting LUXA v4...\n";
                return 0;
            default:
                cout << "Invalid option\n";
        }

        sleep(1);
    }

    return 0;
}
