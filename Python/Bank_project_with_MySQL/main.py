# Banking Program with MySQL......
print('''...............................
////////////////////////<<<--WELCOME IN UNION BANK OF INDIA-->>>////////////////////
////////////////////////////////////////////////////////////////////////////////////
                            ..............................................''')

def new_user_profile():
    print("=======================================================================")
    print("      ---->MENU<---- ")
    print("*   1.Login your Account.....")
    print("*   2.SignUp your Account.....")
    print("***********************************************************************")
    ch=input("Enter your Choice....").strip()
    if ch=="1":
        pass
    elif ch=="2":
        st_list=Sign_Up()
        print(st_list)
        return st_list
    

def Sign_Up():
    typ="1"
    print("=========================================================================")
    print("  Please fill this form with your correct details....   ")
    print("^^^^^^^^^^^^>>>>>>>--------------------<<<<<<<<^^^^^^^^^^^^^^^")
    fname=input(" FIRST NAME = ").title()
    lname=input(" LAST NAME = ").title()
    email = input(" EMAIL = ").lower()
    number =  int(input(" MOBILE NUMBER = "))
    F_name=input(" FATHER'S NAME = ").title()
    address=input(" YOUR ADDRESS = ").title()
    pin = try_except("i","M-PIN MUST BE INTEGER","ENTER M-PIN:- ","1")
    print(" Email Varification Required...")
    st_list=[fname.strip()+" "+lname.strip(),email,number,F_name,pin,address]
    st_list=varification(st_list,typ)
    print(st_list)
    return st_list


def varification(st_list,typ="1"):
    print(" Sending OTP...")
    import Generator
    otp=Generator.Genrate(st_list[0],st_list[1],typ)
    print(" OTP HAS BEEN SENT IN YOUR EMAIL.")
    while True:
        print("==================================================================================================")
        print("     >>>>INSTRUCTION<<<< ","  * FOR LOGIN ENTER OTP ","  * FOR EDIT EMAIL TYPE 1.","  * FOR NEW OTP TYPE 2.","  * FOR EXIT TYPE exit() or 3","",sep="\n")
        print("**************************************************************************************************")
        Check=eval(input(" Enter OTP or INSTRUCTION'S->".upper().format(st_list[1])))
        if Check==otp:
            import Report
            Report.Com_rep(st_list[0].title(),st_list[2],st_list[1],st_list[3])
            print("  Varification Successful..")
            print("  CREATION SUCCESSFULL...")
            break
        elif Check==1:
            Email=input(" Enter your Correct Email Address")
            st_list[1]=Email
            print("=========================================================")
            print(" Sending OTP again")
            print("**********************")
            varification(st_list)
        elif Check==2:
            varification(st_list[0],st_list[1])
        elif Check==3:
            exit()
        else :
            print(" Wrong OTP....")
            print(" **********************")
            print(" Please Enter Correct OTP..")
            print("===============================")
    
    return st_list

def try_except( arrg, msg ,msg_arrg, mode ):
    ar={"i":int,"s":str,"f":float}
    while True:
        if arrg in ar:
            try :
                _na_=ar[arrg](input(" {}".format(msg_arrg)))
                break
            except :
                print(" {}".format(msg))
        elif arrg not in ar:
            print("Wrong arrgument")
            break
    return _na_
            
                                   
  
    
store=new_user_profile()
 #                   >>>>>>>>>>>>>>>>>>>>>>>>:-STORE-:<<<<<<<<<<<<<<<<<<<<<<<<<
class room:
    def __init__(self,name,email,number,father,pin,address):
        self.name=name
        self.email=email
        self.number=number
        self.father=father
        self.pin=pin
        self.address=address
data=room(store[0],store[1],store[2],store[3],store[4],store[5])


while True:
    try:
        eval(input("Enter Command:--"))
    except Exception as e:
        print(e)

def Check_File():
    import os
    try :
        path="C:\\Users\\"+os.getlogin()+"\\AppData\\Local\\Bank_Project"
        if os.path.isfile(path):
            os.mkdir(path)
    except :
        path="C:\\Users\\All Users\\"+os.getlogin()+"AppData\\Local\\Bank_project"
        os.mkdir(path)
        
