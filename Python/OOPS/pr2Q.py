"""
Create Account class with 2 Attributes - balance & account no.
Create methods for debit, credit & printing the balance.
"""

class account:
    def __init__(self, acc_no, balance = 0):
        self.acc_no = acc_no
        self.balance = balance
    
    def debit(self, amount):
        if amount>self.balance:
            print("Insufficient Amount")
        else :
            self.balance -= amount
            print("Rs.", amount, "was debited")
            
    
    def credit(self, amount):
        self.balance += amount
        print("Rs.", amount, "was Credited")
        
    def get_balance(self):
        print("Your Current Balance is:",self.balance)
acc1 = account(200454, 213453)
print(acc1.get_balance())
acc1.debit(213450)
acc1.credit(3000)
acc1.get_balance()