def main():
    print("\t....Main Menu....\n1.Union Bank Managment.\n2.Bakery Shop.\n3.Cosmetic Shop.\n4.Cart")
    choice = int(input("Enter Your Choice:- "))
    if choice == 1:
        Bank_managment()
    elif choice == 2:
        Backery_shop()
    elif choice == 3:
        Cosmetic_shop()
    elif choice == 4:
        exit()
    else :
        print("Invalid Choice")


if __name__ == "__main__":
    while (True):
        main()