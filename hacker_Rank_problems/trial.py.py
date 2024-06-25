import mysql.connector
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
db = database()

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
print(genrate_anum())