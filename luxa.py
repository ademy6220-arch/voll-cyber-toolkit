Oimport os
import platform
import socket
import datetime

LOG_FILE = "luxa_log.txt"


def log(text):
    with open(LOG_FILE, "a") as f:
        f.write(f"[{datetime.datetime.now()}] {text}\n")


def banner():
    print("""
██╗     ██╗   ██╗██╗  ██╗ █████╗ 
██║     ██║   ██║██║  ██║██╔══██╗
██║     ██║   ██║███████║███████║
██║     ██║   ██║██╔══██║██╔══██║
███████╗╚██████╔╝██║  ██║██║  ██║
╚══════╝ ╚═════╝ ╚═╝  ╚═╝╚═╝  ╚═╝

   LUXA SECURITY TOOL v2.0
   (educational only)
""")


def system_info():
    print("\n[ SYSTEM INFO ]")
    info = {
        "OS": platform.system(),
        "Version": platform.version(),
        "Machine": platform.machine(),
        "Processor": platform.processor()
    }

    for k, v in info.items():
        print(f"{k}: {v}")
        log(f"SystemInfo {k}: {v}")


def network_info():
    print("\n[ NETWORK INFO ]")
    hostname = socket.gethostname()
    ip = socket.gethostbyname(hostname)

    print("Hostname:", hostname)
    print("Local IP:", ip)

    log(f"Network Hostname: {hostname}, IP: {ip}")


def file_scan():
    print("\n[ FILE SCAN ]")
    os.system("ls -lah")
    log("File scan executed")


def process_view():
    print("\n[ PROCESSES ]")
    os.system("ps aux | head -n 15")
    log("Process view executed")


def menu():
    while True:
        print("\n====== LUXA MENU ======")
        print("1. System Info")
        print("2. Network Info")
        print("3. File Scan")
        print("4. Process Viewer")
        print("5. Exit")

        choice = input("Select option: ")

        if choice == "1":
            system_info()
        elif choice == "2":
            network_info()
        elif choice == "3":
            file_scan()
        elif choice == "4":
            process_view()
        elif choice == "5":
            print("Exiting LUXA...")
            log("Program exited")
            break
        else:
            print("Invalid option")


banner()
menu()
