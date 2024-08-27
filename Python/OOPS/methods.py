# Methods are basically Functions that belong to classes
class Student:
    # Class Attributes
    clg_name = "PSIT"
    
    def __init__(self, name, marks):
        self.name = name
        self.marks = marks
    
    def welcome(self):
        print("Welcome Student", self.name)
    
    
    def get_marks(self):
        return self.marks

s1 = Student("Abhi", 64)
print(s1.get_marks())