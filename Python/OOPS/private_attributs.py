class Account:
    def __init__(self, acc_no, acc_pass):
        self.acc_no = acc_no
        # Double Underscore is used to create a private attribute
        # It is meant to used inside the class only
        self.__acc_pass = acc_pass
    
    def show_pass(self):
        print(self.__acc_pass)

acc1 = Account("12234", "asdfsd")
print(acc1.acc_no)
acc1.show_pass()