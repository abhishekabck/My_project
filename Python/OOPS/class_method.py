"""
A class method is bound to the class & receives the class as an implicit first arguments.
Note:- static method can't access or modify class state & generally for utility.
"""

class Person:
    name = "anonymous"
    
    # Instance Method
    # def changeName(self, name):
    #     # self.name = name
    #     # Person.name = name
    #     self.__class__.name = "Rahul"
    
    @classmethod # decorator
    def changeName(cls, name):
        cls.name = "Rahul"
    
p1 = Person()
p1.changeName("rahul kumar")
print(p1.name)
print(Person.name)
# Person.name = "Abhishek"
# p2 = Person()
# print(p2.name)

