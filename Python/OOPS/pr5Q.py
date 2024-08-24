"""
Create a class Order which stores item & its price.
Use Dunder fucntion __gt__() to convey that:
    order1>order2 if price of order1>price of order2
"""
class Order:
    def __init__(self, item, price) -> None:
        self.item = item
        self.price = price
    
    def __gt__(self, order):
        return self.price > order.price

or1 = Order("Cake", 56)
or2 = Order("Biscuit", 30)
print(or2>or1)