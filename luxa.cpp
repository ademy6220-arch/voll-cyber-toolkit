#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

void banner() {
    cout << R"(
██╗     ██╗   ██╗██╗  ██╗ █████╗ 
██║     ██║   ██║██║  ██║██╔══██╗
██║     ██║   ██║███████║███████║
██║     ██║   ██║██╔══██║██╔══██║
███████╗╚██████╔╝██║  ██║██║  ██║
╚══════╝ ╚═════╝ ╚═╝  ╚═╝╚═╝  ╚═╝

   LUXA CYBER TOOL v3 (C++)
   Educational Security Toolkit
)" << endl;
}

void systemInfo() {
    cout << "\n[ SYSTEM INFO ]\n";
    system("uname -a");
}

void networkInfo() {
    cout << "\n[ NETWORK INFO ]\n";
    system("hostname");
    system("ip a | head -n 10");
}

void fileScan() {
    cout << "\n[ FILE SCAN ]\n";
    system("ls -lah");
}

void processView() {
    cout << "\n[ PROCESSES ]\n";
    system("ps aux | head -n 15");
}

int main() {
    int choice;

    banner();

    while (true) {
        cout << "\n====== LUXA MENU ======\n";
        cout << "1. System Info\n";
        cout << "2. Network Info\n";
        cout << "3. File Scan\n";
        cout << "4. Process Viewer\n";
        cout << "5. Exit\n";
        cout << "Select: ";
        cin >> choice;

        switch(choice) {
            case 1:
                systemInfo();
                break;
            case 2:
                networkInfo();
                break;
            case 3:
                fileScan();
                break;
            case 4:
                processView();
                break;
            case 5:
                cout << "Exiting LUXA v3...\n";
                return 0;
            default:
                cout << "Invalid option\n";
        }
    }

    return 0;
}
