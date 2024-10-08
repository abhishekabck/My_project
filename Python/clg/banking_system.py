def menu(amount):
    print("Please Choose The action You wish to Perform:-")
    print("1.Withdraw Money.")
    print("2.Deposit Money.\n3.Display Balance.\n4.Exit/Quit.")
    choice = int(input("Enter Your Choice:- "))
    if (choice == 1):
        amt = int(input("Enter the amount You Wish to Withdraw::"))
        if amt>amount:
            print("Insufficient funds\t")
        else:
            print("Withdrawal SuccessFull")
            amount -= amt
        
    elif (choice == 2):
        amt = int(input("Enter the amount You Wish to Withdraw::"))
        print("Ammount updated")
        amount += amt
        print("New Ammount::-", amount)
        
    elif (choice == 3):
        print(amount)
    else:
        exit()


while True:
    menu(0)