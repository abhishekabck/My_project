# Data
def G_mail():
    # mail
    import os
    fd=os.open("mail",os.O_RDONLY)
    data=os.read(fd,1000).decode()
    L_data=data.split("-")
    mail=""
    for i in range(0,len(L_data)):
        mail+=chr(int(L_data[i]))
    os.close(fd)
    return mail


def G_pass():
    import os
    password=""
    fd=os.open("pass",os.O_RDONLY)
    data=os.read(fd,100).decode()
    L_data=data.split("-")
    for i in L_data:
        password+=chr(int(i))
    os.close(fd)
    return password
