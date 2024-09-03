import mysql.connector

class Database:
    def __init__(self, database = "default") :
        self.cnx = mysql.connector.connect(
            user = "root",
            password = "5844",
            port = "3306",
            host = "localhost",
            database = self.database
        )
        self.cur = self.cnx.cursor()
    @property
    def isconnected(self):
        return self.cnx.is_connected()

class Bank(Database):
    @property
    def exc(self, query:str):
        self.cur.execute(query)
        
    def login(self, account_no, m_pin):
        self.exc("use Workplace1")
        self.exc("")
        