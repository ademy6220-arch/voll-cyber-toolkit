import os
import json
import datetime

BANNER = r"""
██╗     ██╗   ██╗██╗  ██╗ █████╗
██║     ██║   ██║╚██╗██╔╝██╔══██╗
██║     ██║   ██║ ╚███╔╝ ███████║
██║     ██║   ██║ ██╔██╗ ██╔══██║
███████╗╚██████╔╝██╔╝ ██╗██║  ██║
╚══════╝ ╚═════╝ ╚═╝  ╚═╝╚═╝  ╚═╝

      LUXA Research Toolkit
"""

DATA = {
    "notes": [],
    "targets": []
}

def clear():
    os.system("clear")

def pause():
    input("\n[ENTER] Continue...")

def save_data():
    with open("luxa_data.json", "w") as f:
        json.dump(DATA, f, indent=4)

def load_data():
    global DATA
    if os.path.exists("luxa_data.json"):
        try:
            with open("luxa_data.json", "r") as f:
                DATA = json.load(f)
        except:
            pass

def add_note():
    note = input("Note: ")
    DATA["notes"].append({
        "text": note,
        "time": str(datetime.datetime.now())
    })
    save_data()
    print("Saved.")

def show_notes():
    if not DATA["notes"]:
        print("No notes.")
        return

    for i, note in enumerate(DATA["notes"], start=1):
        print(f"\n[{i}]")
        print(note["text"])
        print(note["time"])

def add_target():
    target = input("Target Name: ")

    DATA["targets"].append({
        "name": target,
        "created": str(datetime.datetime.now())
    })

    save_data()
    print("Target added.")

def show_targets():
    if not DATA["targets"]:
        print("No targets.")
        return

    for i, target in enumerate(DATA["targets"], start=1):
        print(f"\n[{i}] {target['name']}")
        print(f"Created: {target['created']}")

def statistics():
    print("\n=== Statistics ===")
    print(f"Notes   : {len(DATA['notes'])}")
    print(f"Targets : {len(DATA['targets'])}")

def export_report():
    filename = "luxa_report.txt"

    with open(filename, "w") as f:
        f.write("LUXA REPORT\n")
        f.write("=" * 40 + "\n\n")

        f.write("TARGETS\n")
        f.write("-" * 20 + "\n")

        for t in DATA["targets"]:
            f.write(f"{t['name']} | {t['created']}\n")

        f.write("\nNOTES\n")
        f.write("-" * 20 + "\n")

        for n in DATA["notes"]:
            f.write(f"{n['time']}\n")
            f.write(f"{n['text']}\n\n")

    print(f"Exported: {filename}")

def menu():
    print(BANNER)
    print("[1] Add Note")
    print("[2] Show Notes")
    print("[3] Add Target")
    print("[4] Show Targets")
    print("[5] Statistics")
    print("[6] Export Report")
    print("[0] Exit")

def main():
    load_data()

    while True:
        clear()
        menu()

        choice = input("\nSelect > ")

        clear()

        if choice == "1":
            add_note()

        elif choice == "2":
            show_notes()

        elif choice == "3":
            add_target()

        elif choice == "4":
            show_targets()

        elif choice == "5":
            statistics()

        elif choice == "6":
            export_report()

        elif choice == "0":
            break

        else:
            print("Invalid option.")

        pause()

if __name__ == "__main__":
    main()
