"""
Polymorphism :: Operator Overloading
When the same operator is allowed to have different meaning according to the context.
"""

# operator & dunder Functions:- fucntion starting with __

class Complex:
    def __init__(self, real, imag):
        self.real = real
        self.img = imag
    
    def showNumber(self):
        print(self.real,"i +", self.img,"j")
    
    def __add__(self, num2):
        newReal = self.real + num2.real
        newImag = self.img + num2.img
        return Complex(newReal, newImag)
    
    def __sub__(self, num2):
        newReal = self.real - num2.real
        newImag = self.img - num2.img
        return Complex(newReal, newImag)

num1 = Complex(1,3)
num1.showNumber()

num2 = Complex(4,6)
num2.showNumber()

num3 = num1 + num2
num3.showNumber()

num3 = num2 - num1
num3.showNumber()
