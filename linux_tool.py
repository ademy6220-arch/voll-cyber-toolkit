import os

while True:
    print("\n=== LINUX TOOL ===")
    print("1. Show current directory")
    print("2. List files")
    print("3. Create directory")
    print("4. Create file")
    print("5. Exit")

    choice = input("Choose option: ")

    if choice == "1":
        os.system("pwd")

    elif choice == "2":
        os.system("ls")

    elif choice == "3":
        name = input("Folder name: ")
        os.system(f"mkdir {name}")
        print("Folder created!")

    elif choice == "4":
        name = input("File name: ")
        os.system(f"touch {name}")
        print("File created!")

    elif choice == "5":
        print("Goodbye 👋")
        break

    else:
        print("Invalid choice")
