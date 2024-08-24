"""
Create Student class that takes name & marks of 3 Subjects as arguments in constructor.
Then create a method to print the average.
"""

class Student:
    def __init__(self, name, marks):
        self.name = name
        self.marks = marks
        
    def get_avg(self) -> float:
        sum = 0
        for val in self.marks:
            sum += val
        print("Hi", self.name, "Your avg score is:",round(sum/len(self.marks), 2))
    
s1 = Student("Name1", (45,64, 67))
s2 = Student("Name2", (56, 67, 45))
s1.get_avg()
s2.get_avg()