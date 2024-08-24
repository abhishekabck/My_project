"""                 Four Pillers of Oops Concepts
                                ||
    ____________________________||_____________________________
    ||                 ||                 ||                 ||
Abstraction        Encapsulation       Inheritence       Polymorphisome


"""

# Abstraction::
# Abstraction:- Hiding the implementation details of a class and only showing the essential features to the user.
class car:
    def __init__(self):
        self.acc = False
        self.brk = False
        self.clutch = False
        
    def start(self):
        self.clutch = True
        self.acc = True
        print("Car started.. ")
        
car1 = car()
car1.start()

# Encapsulation::
# Wrapping data and functions into a single unit(object).
