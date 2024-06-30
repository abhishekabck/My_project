# Banking Program with MySQL......
import os
import xlsxwriter
import mysql.connector
from re import search as srch

print('''       WELCOME IN UNION BANK OF INDIA''')


class database:
    """
    This Class Fucntion is just to connects The program to Database
    """
    def __init__(self) :
        self.cnx = mysql.connector.connect(
            user = "root",
            password = "5844",
            port = "3306",
            host = "localhost",
            database = "director"
        )
        self.cur = self.cnx.cursor()

class excel_writter:
    def __init__(self):
        self.file = self.get_fname()
        self.fname = None
    
    def get_fname(self):
        struct = "Bank_statement.xlsx"
        path = os.getcwd()
        ls = os.listdir(path)
        if struct not in ls:
            self.fname = struct
            return path + "\\" + struct
        Max = struct
        for fname in ls:
            re_var = srch(struct,fname)
            if re_var != None and fname != struct:
                Max = max(Max,fname)
        if (Max == struct):
            self.fname = Max[:14]+"1"+Max[14:]
        else :
            rv = srch(".",Max)
            self.fname = Max[:14] + str(int(Max[14:rv.start+1])+1) + Max[rv.start:]
        return path + "\\" + self.fname
    
    def get_file(self,f_list):
        self.get_fname()
        work_book = xlsxwriter.Workbook(self.file)
        worksheet = work_book.add_worksheet()
        f_list = [("Account No","Date","Refrence","Withdraw","Deposite")] + f_list
        for row in range(len(f_list)):
            for cols in range(len(f_list[row])):
                if (row == 0): # for First row
                    worksheet.write(row,cols,f_list[row][cols])
                elif (cols == 3) and (int(f_list[row][cols]) < 0): ## withdrawal Case
                    worksheet.write(row,cols,str(int(f_list[row][cols])*-1))
                    worksheet.write(row,cols+1,'0')
                elif (cols == 3) and (int(f_list[row][cols]) > 0):  # case for Deposite
                    worksheet.write(row,cols,'0')
                    worksheet.write(row,cols+1,f_list[row][cols])
                else : # if row in nither 1 and column in nither 0
                    worksheet.write(row,cols,f_list[row][cols])
        work_book.close()
        return self.fname
        

class tranc:
    def __inti__(self,a_no = None,cursor = None,db = None):
        self.a_no = a_no
        self.cur = cursor
        self.db = db
    
    def Update(self,amount,ref = "Bank Deposite"):
        if ref != "Bank Deposite" and (amount<0):
            ref = "Bank Withdrawal"
        self.cur.execute(f'Insert into bank_statements (acc_no,action,reference) value("{self.a_no}",{amount},"{ref}");')
        db.cnx.commit()
        
    def change(self,amount):
        self.cur.execute(f'Update bank_money set ammount = ammount + {amount} where acc_no = "{self.a_no}";')
        print("Ammount Updated Successfully..")
        self.Update(amount)
        db.cnx.commit()
        
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
tr = tranc()
xl = excel_writter()
tr.db = db.cnx
tr.cur = db.cur

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
    db.cur.execute(f'Insert into bank_money values("{det.a_no}",{0});')
    db.cnx.commit()
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
    if  _uch == "yes":
        try :
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
    print("Details Updated Successfully.\nGenerating Account number..")
    det.a_no = genrate_anum()
    print("Your Account No is :-",det.a_no)
    det.m_pin = input("Please Create your 4 digit M_pin")
    while (len(det.m_pin)!=4):
        det.m_pin = input("length of m_pin does not meets requirment\n Please Re-enter your 4 digit Mpin:-")
    update_signup()
    
def acc_details(account):
    db.cur.execute(f'Select * from bank_credentials where acc_no = "{account}"')
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
    choice()
    
def check_auth(amount,typ):
    if typ == "w":
        if amount>20000:
            return True
        return False
    elif typ == "a" :
        if amount >50000:
            return True
        return False


def transction(typ):
    tr.a_no = det.a_no
    if (typ == -1): #Withdraw Money
        am = int(input("Enter the Ammount you wish to withdraw from your account:-"))
        while (check_auth(am,"w")):
            print("Warning ::You can only withdraw 20000.")
            am = int(input("Enter the Ammount you wish to withdraw from your account:-"))
        tr.change(am*int(typ))
        choice()
    elif (typ == 1): # Deposite Money
        am = int(input("Enter the Ammount you wish to Add in your account:-"))
        while (check_auth(am,"a")):
            print("Warning ::You can only add upto 50000.")
            am = int(input("Enter the Ammount you wish to withdraw from your account:-"))
        tr.change(am*int(typ))
        choice()
    db.cnx.commit()

def choice():
    if input("\nDo You wish to continue (y/n):-").lower() == "y":
        print("\n")
        login_menu()
    else :
        print("::<>::Thank You! For Choosing Union Bank of India::<>::")
        exit(0)


def bank_balance():
    db.cur.execute(f"Select ammount from bank_money where acc_no = \"{det.a_no}\";")
    c_amount = int(list(db.cur)[0][0])
    print("\nYour Current Bank Ammount is::",c_amount)
    choice()


def bank_statment():
    try:
        ch = int(input("Formats Of Bank Statement..\n1.Just Display Statement Here.\n2.Get Excel File.\n Enter your choice here(1,2):- "))
    except:
        print("Wrong Choice..")
        login_menu()
    db.cur.execute(f"Select acc_no,date_time,reference,action from bank_statements where acc_no = \"{det.a_no}\"")
    data_ar = list(db.cur)
    if ch == 1:
        os.system("cls")
        print(f" User Details:- \n Account No. :: {det.a_no}\n Name :: {det.name} \n")
        print("  Withdrawal \t Deposite \t Date \t Reference")
        for tp1 in data_ar:
            if int(tp1[-1]) < 0 :
                print(f"\t{int(tp1[-1])*-1}\t\t\t{tp1[1]}\t{tp1[2]} ")
            else :
                print(f" \t\t\t{int(tp1[-1])}\t{tp1[1]}\t{tp1[2]}")
        
        choice()
    elif ch == 2:
        print("Your Except file File name:-",xl.get_file(data_ar))
        print("Path = "+xl.file)
        choice()
        

def logout():
    det.name = det.a_no = det.address = det.age = det.carrier = det.email = det.m_pin = det.phone = None
    print("log_out Successfull")
    if input("Do you wish to Go back Main menu (y/n):-").lower() == "y":
        main()
    else :
        exit()


def login_menu():
    print("Please Choose The action You wish to Perform:-")
    print("1.Personal Details:-\n2.Withdraw Money.")
    print("3.Add Money.\n4.Bank Balance.\n5.Bank Statment.\n6.logout \n7.Exit/Quit.")
    choice = int(input("Enter Your Choice:- "))
    if (choice == 1):
        show_details()
    elif (choice == 2):
        transction(-1)
    elif (choice == 3):
        transction(1)
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
    det.a_no = input(" Enter Your 10 Digit Account Number:-")
    if acc_details(det.a_no) == False:
        print("Account Number Does not Found\n::Please Try another Account Number::\n\n")
        login()
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
