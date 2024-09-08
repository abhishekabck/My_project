
class Bank_front:
    def front_menu(self):
        print("Welcome To Digital Bank..")
        print("Available Options: Please select any one of these..")
        print("1.Login")
        print("2.SignUp")
        print("3.Exit")
    
    def login_menu(self):
        print("Please Fill Up the Following details To login in your account")
        self.acc_no = input("Enter Your Account Number: ")
        self.Pass = input("Enter Your Password: ")
        if self.login(self.acc_no, self.Pass) == False:
            print("The Details Entered by User is Invalid..")
            self.front_menu()
        self.login_sub()
    
    def login_sub(self):
        print("Enter Your Choice: ")
        print("1.Deposite Money..")
        print("2.Withdraw Money..")
        