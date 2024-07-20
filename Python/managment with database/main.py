import bank_managment as bm

def main():
    print("\t....Main Menu....\n1.Union Bank Managment.\n2.Bakery Shop.\n3.Cosmetic Shop.\n4.Cart")
    choice = int(input("Enter Your Choice:- "))
    if choice == 1:
        bm.main()
    elif choice == 2:
        pass
        #Backery_shop()
    elif choice == 3:
        pass
        #Cosmetic_shop()
    elif choice == 4:
        exit()
    else :
        print("Invalid Choice")


if __name__ == "__main__":
    while (True):
        main()