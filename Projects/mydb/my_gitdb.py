import json
class __git_details:
    def __init__(self):
        self.__email :str
        self.__password : str
    
    def connect(self):
        pass


class m_offline:
    def __init__(self):
        self._pos = ""
        self.empty = True
    
    @property
    def isconnected(self):
        try :
            with open(f"{self.pos}","a") as __f:
                if __f.tell() == 0: self.empty = True
        except:
            self.empty = False

class Database(__git_details,m_offline):
    def __init__(self):
        self.path = 
    
    def connect(self,Email:str = None, Pass:str = None, mode = "off"):
        if mode == "off":
            path = m_offline._pos
        