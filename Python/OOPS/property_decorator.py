class Student:
    def __init__(self, phy, chem, math):
        self.phy = phy
        self.chem = chem
        self.math = math
    
    @property
    def percentage(self):
        return str((self.phy + self.chem + self.math) / 3) + "%"
        
stu1 = Student(98, 97, 99)
print(stu1.percentage)
# stu1.phy = 86
# print(stu1.phy)
# print(stu1.percentage())
# To replace the mannual change of any function we use property decorator which converts any function as property and updates value
stu1.phy = 47
print(stu1.percentage)

# gettter and setter