shopping_basket = {}
print("Welcome to the online drink store!\nThese are the drinks we offer\n1. Lemonade: £1.50\n2. Coke: £2.00\n3. Fanta £1.00\n4. Water: £0.50")

Price = {"Lemonade": 1.50, "Coke": 2.00, "Fanta": 1.00, "Water": 0.50 }

option = int(input("Which drink would you like to purchase?: "))
while option!= 0:
    if option == 1:
        qnty = int(input("Enter the quantity: "))
        total = qnty * 1.50
        print("The price is: " + str(total))
    elif option == 2:
        qnty = int(input("Enter the quantity: "))
        total = qnty * 2.00
        print("The price is: " + str(total))
    elif option == 3:
        qnty = int(input("Enter the quantity: "))
        total = qnty * 1.00
        print("The price is: " + str(total))
    elif option == 4:
        qnty = int(input("Enter the quantity: "))
        total = qnty * 0.50
        print("The price is: " + str(total))

        print("Would you like another item? enter Yes or No:")
    else:
        print("The total price of your basket is: " , total = Price * qnty)
