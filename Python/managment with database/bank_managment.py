# Banking Program with MySQL......
import os
import datetime
import mysql.connector

print('''       WELCOME IN UNION BANK OF INDIA''')

class database:
    def __init__(self) :
        self.cnx = db = mysql.connector.connect(
            user = "root",
            password = "5844",
            port = "3306",
            host = "localhost",
            database = "director"
        )
        self.cur = self.cnx.cursor()

class tranc:
    def __inti__(self,a_no = None):
        self.a_no = a_no
    def change = 
class details:
    def __init__(self,name = "User",
                 a_no = "UN00BOI000",
                 phone = 1111111111,
                 address = "xXXx",
                 email = "x@y.com" ,
                 m_pin = "0011",age = 4):
        self.name = name
        self.a_no = a_no
        self.phone = phone
        self.address = address
        self.email = email
        self.m_pin = m_pin
        self.age = age
        self.carrier = ""
    
det = details()
db = database()


def main():
    #print("=======================================================================")
    print("      ---->MENU<---- ")
    print("1.Login your Account:")
    print("2.Create an account:")
    ch=input("Enter your Choice....").strip()
    if ch=="1":
        print("::Creating Login Environment::")
        login()
    elif ch=="2":
        print("::Creating Sign Up environment::")
        os.system("cls")
        Sign_Up()

# Generates Next account Number of new user
def genrate_anum():
    db.cur.execute("select * from bank_credentials;")
    data = list(db.cur)
    if len(data) < 1:
        lst_account = "UN00BOI000"
    else :
        lst_account = data[-1][0]
    n_ac_no = int(lst_account[2:4] + lst_account[7:])+1
    if (n_ac_no > 99999):
        print("Warning :: Database is Full")
        exit(0)
    ln = str(n_ac_no%1000)
    fn = str(n_ac_no//1000)
    while ((len(ln) != 3) or (len(fn) != 2)):
        if (len(ln)<3):
            ln = "0" + ln
        if (len(fn))<2:
            fn = "0" + fn
    return "UN" + fn + "BOI" + ln

# This Fucntion insert all new values from class details into the database table.
def update_signup():
    db.cur.execute(f'Insert into bank_credentials values("{det.a_no}","{det.name}",{det.phone},{det.age},"{det.address}","{det.email}","{det.m_pin}")')
    print("Your Account is Successfully Created..\n\n Do You wish to Login in your account?(yes/no)",end = "")
    ch = input().lower()
    while (ch not in ("yes","no")):
        print("Wrong Choice.\nPlease enter Correct Choice:-")
        ch = input().lower()
    if (ch == "yes"):
        login()
    else :
        print("Thank You for Choosing Union Bank of India:-\n")
        os.system("cls")
        main()
        
# Fucntion needed to be called to create account
def Sign_Up():
    print("\n ->Please fill this form with your correct details....   ")
    fname=input(" FIRST NAME:- ")
    lname=input(" LAST NAME:- ")
    det.name = fname + " " + lname
    det.age = int(input(" Please Enter Your Age:-"))
    det.phone =  int(input(" MOBILE NUMBER = "))
    det.email = input(" EMAIL:- ")
    det.address = input(" YOUR ADDRESS:- ")
    input(" Press any key to Proceed:- ")
    os.system("cls")
    print(f"Your Details:- \n 1. Name = {det.name}  2. Age = {det.age} \n 3. Mobile number = {det.phone} \n 4. Email Address = {det.email} \n 5. Address = {det.address} ")
    print("Please Confirm Your details:- ")
    _uch = input("Do you wish to Change Anything? (Yes/No) : ").lower()
    while ( _uch not in ("yes","no")):
        print("Wrong Choice..\n Please Choose Correct Option.")
        _uch = input("Do you wish to Change Anything? (Yes/No) : ").lower()
    try: 
        if  _uch == "yes":
            _ = {"Name ":"det.name","Age": "det.age","Mobile Number":"det.phone","Email":"det.email","Address":"det.address"}
            _keys = [i for i in _]
            change = tuple(map(int, input("Please Enter the Number persent in front of detail to change data.\nFor More than one variable change enter numbers by seperating them by Comma(,) \n Your Choice:-").split(",")))
            for i in change:
                data = input(f"Please Enter your {_keys[i-1]} :- ")
                eval(f"_[_keys[i-1]] = {data}")
            print("Your Details Have been Updated.")
            os.system("cls")
            print(f"Your Details:- \n 1. Name = {det.name}  2. Age = {det.age} \n 3. Mobile number = {det.phone} \n 4. Email Address = {det.email} \n 5. Address = {det.address} ")
    except :
        print("Due to Wrong Choice Details will Proceed as they were initial")
    else :
        print("Details Updated Successfully.\nGenerating Account number..")
        det.a_no = genrate_anum()
        print("Your Account No is :-",det.a_no)
        update_signup()
    
def acc_details(account):
    db.cur.execute(f'Select * from bank_credentials where acc_no == "{account}"')
    data = list(db.cur)
    if len(data) == 0:
        return False
    else :
        det.carrier = data
        return True
    
def show_details():
    # Prints the Details of the current login User
    os.system("cls")
    print("--->> Union Bank of India <<----")
    print("Personal Details are given as:-")
    print(f"--> Account No:- {det.a_no}\n--> Name:- {det.name}\n--> Age:- {det.age}")
    print(f"--> Mobile Number:- {det.phone}\n--> Email :- {det.email}\n--> Address:- {det.address}")
    
    
def transction(typ):
    if (typ == -1): # Withdraw
        
            

def bank_balance():
    pass

def bank_statment():
    pass

def logout():
    pass


def login_menu():
    print("Please Choose The action You wish to Perform:-")
    print("1.Personal Details:-\n2.Withdraw Money.")
    print("3.Add Money.\n4.Bank Balance.\n5.Bank Statment.\n6.logout \n7.Exit/Quit.")
    choice = int(input("Enter Your Choice:- "))
    if (choice == 1):
        show_details()
    elif (choice == 2):
        transction("-1")
    elif (choice == 3):
        transction("+1")
    elif (choice == 4):
        bank_balance()
    elif choice == 5:
        bank_statment()
    elif choice == 6:
        logout()
    elif choice == 7:
        exit(0)
    else :
        print("Wrong Choice:-")
        os.system("cls")
        
        
        

def login():
    print("\n Please Fill the following Details to login your Account")
    det.a_no = input(" Enter Your Account Number:-")
    if acc_details(det.a_no) == False:
        print("Wrong Account Number..")
        # Need to write fucntion to fing account Number
    else :
        if (input(" Please Enter Your M_pin:- ") == det.carrier[-1][-1]):
            print("Account Varification SuccessFull..")
            det.name = det.carrier[0][1]
            det.phone = det.carrier[0][2]
            det.age = det.carrier[0][3]
            det.address = det.carrier[0][4]
            det.email = det.carrier[0][5]
            det.m_pin = det.carrier[0][6]
            login_menu()
        
        
    
main()
