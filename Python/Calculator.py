class calculator:
    def __init__(self, num1, num2):
        self.num1 = num1
        self.num2 = num2
        self.ls = []
    
    def __add__(self):
        return self.num1+self.num2
    def __subtract__(self):
        return self.num1 + self.num2
    def __multiply__(self):
        return self.num1*self.num2
    def __devide__(self):
        return self.num1/self.num2
    def __len__(self):
        return len(self.ls)
    def __append__(self):
        self.ls.append(self.num1)
        self.ls.append(self.num2)
        return "Success"
if __name__=="__main__":
    n1 = int(input("Enter First integer"))
    n2 = int(input("Enter Second integer"))
    digits = calculator(n1,n2)
    print(append(digits))
    print(len(digits))