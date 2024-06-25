import mysql.connector

class __data__:
    def __init__(self, username = "root", password = "ef66yrnce"):
        self.user = username
        self.password = password

class _MySql_module_:
    def __init__(self, username, password):
        c1 = __data__(password=5844)
        self.user  = c1.user
        self.password = c1.password
    
    def _connect_(self):
        db = mysql.connector.connect(user = self.user, port = 8080, password = self.password)

det = __data__()
s2 = _MySql_module_()
s2._connect_();
        