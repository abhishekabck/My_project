# Inheriting Properties multiple classes

class A:
    varA = "Welcome to class A"
    
class B:
    varB = "Welcome to class B"

class C(A,B):
    varC = "Welcome to class C"

c1 = C()
print(c1.varA, c1.varB, c1.varC, sep = "\n")