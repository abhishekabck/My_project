"""
Class & Instance Attribute
Two types of attribute
1. Class Attribute
2. Object Attribute ->> Have Higher Priority than class Atrributes
"""

class Student:
    # Class Attributes
    clg_name = "PSIT"
    name = "anonymous"
    
    def __init__(self, marks, name = name):
        self.name = name
        self.marks = marks
    
s1 = Student("Abhishek", 97)
s2 = Student(64)
print(s1.name, s1.marks, s1.clg_name)
