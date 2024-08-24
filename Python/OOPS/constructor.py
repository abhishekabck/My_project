# All classes have a fucnction called __init__(), which is always executed when the object is being initiated.
# we can create more than one constructor in class
# Creating class
class Student:
    # default constructor
    def __init__(self) :
        pass
    
    # Paramenterized Constructor
    def __init__(self, name, marks): # constructor for class Student
        # all constructor have a self paramenter.
        print(self)
        # points the calling object
        self.name = name
        self.marks = marks
        print("Adding new Student to Database.. ")

s1 = Student
s1.name = "abhishek"
s1.marks = "45"
print(s1.name, s1.marks)

"""
The self paramenter is a reference to the current instance of the class,
and is used to access variables that belongs to the class
"""

s2 = Student("Abhishek", 89)
print(s2.name, s2.marks)