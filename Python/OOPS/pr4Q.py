"""
Define a Employee class with attributes role, department & salary.
This class also has a showDetails() method.
Create an Engineer class that inherits properties from Employees
and has additional attributes: name & age.
"""

class Employee:
    def __init__(self, role, department, salary):
        self.department = department
        self.role = role
        self.salary = salary
    
    def showDetails(self):
        print("Role:",self.role,"\nDepartment:",self.department,"\nSalary:",self.salary)

class Engineer(Employee):
    def __init__(self, name, age, dept, salary):
        self.name = name
        self.age = age
        super().__init__("Engineer",dept, salary)

engg1 = Engineer("Elon Mask", 40, "Mechanical", "12,00,000")
engg1.showDetails()
    