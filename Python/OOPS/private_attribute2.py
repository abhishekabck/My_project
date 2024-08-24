"""
Private(like) attributes & methods are meant to be used only withing
the class and are not accessible from outside the class."""

class Person:
    __name = "anonymous"
    
    def __hello(self):
        print("Hello Person")
        
    def welcome(self):
        self.__hello()

p1 = Person()
p1.welcome()