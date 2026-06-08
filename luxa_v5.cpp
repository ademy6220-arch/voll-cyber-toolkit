#include <iostream>
#include <cstdlib>
#include <fstream>
#include <ctime>

using namespace std;

string logFile = "luxa.log";
string jsonFile = "luxa_report.json";

string getTime() {
    time_t now = time(0);
    return ctime(&now);
}

void writeLog(string text) {
    ofstream log(logFile, ios::app);
    log << "[" << getTime() << "] " << text << endl;
    log.close();
}

void writeJSON(string data) {
    ofstream json(jsonFile, ios::app);
    json << data << endl;
    json.close();
}

void banner() {
    cout << R"(
=============================
   LUXA CYBER TOOL v5
   Logging + JSON System
=============================
)" << endl;

    writeLog("LUXA started");
}

void systemInfo() {
    cout << "\n[ SYSTEM INFO ]\n";
    system("uname -a");

    writeLog("System info executed");
    writeJSON("{\"module\":\"system\",\"status\":\"ok\"}");
}

void networkInfo() {
    cout << "\n[ NETWORK INFO ]\n";
    system("hostname");
    system("ip a | head -n 10");

    writeLog("Network info executed");
    writeJSON("{\"module\":\"network\",\"status\":\"ok\"}");
}

void fileScan() {
    cout << "\n[ FILE SYSTEM ]\n";
    system("ls -lah");

    writeLog("File scan executed");
    writeJSON("{\"module\":\"filesystem\",\"status\":\"ok\"}");
}

void processView() {
    cout << "\n[ PROCESSES ]\n";
    system("ps aux | head -n 15");

    writeLog("Process view executed");
    writeJSON("{\"module\":\"process\",\"status\":\"ok\"}");
}

void exportReport() {
    cout << "\n[ EXPORT REPORT ]\n";

    ofstream json(jsonFile);
    json << "{\n";
    json << "  \"tool\": \"LUXA v5\",\n";
    json << "  \"status\": \"session saved\",\n";
    json << "  \"modules\": [\"system\", \"network\", \"files\", \"process\"],\n";
    json << "  \"note\": \"educational cybersecurity toolkit\"\n";
    json << "}\n";

    json.close();

    writeLog("JSON report exported");
    cout << "Report saved to luxa_report.json\n";
}

int main() {
    int choice;

    banner();

    while (true) {
        cout << "\n====== LUXA v5 MENU ======\n";
        cout << "1. System Info\n";
        cout << "2. Network Info\n";
        cout << "3. File Scan\n";
        cout << "4. Process Viewer\n";
        cout << "5. Export JSON Report\n";
        cout << "6. Exit\n";
        cout << "Select: ";

        cin >> choice;

        switch(choice) {
            case 1: systemInfo(); break;
            case 2: networkInfo(); break;
            case 3: fileScan(); break;
            case 4: processView(); break;
            case 5: exportReport(); break;
            case 6:
                writeLog("LUXA exited");
                cout << "Goodbye\n";
                return 0;
            default:
                cout << "Invalid option\n";
        }
    }

    return 0;
}
