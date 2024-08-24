class Student:
    def __init__(self, name) -> None:
        self.name = name

s1 = Student("Name")
print(s1.name)
del s1.name
# It can deletes any Properties
del s1
#It can deletes whole object
print(s1)