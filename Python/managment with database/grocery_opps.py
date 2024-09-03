
class Database:
    def __init__(self):
        self.__items = {
            "VF001":{"name": "Apples", "price": 75, "unit": "Kg"},
            "VF002":{"name": "Carrots", "price": 50, "unit": "Kg"},
            "VF003":{"name": "Tomatoes", "price": 35, "unit": "Kg"},
            "VF004":{"name": "Grapes", "price": 40, "unit": "Kg"},
            "VF005":{"name": "Bananas", "price": 50, "unit": "12pcs"},
            "GR001":{"name": "Rice", "price": 50, "unit": "Kg"},
            "GR002":{"name": "Pasta", "price": 30, "unit": "Kg"},
            "GR003":{"name": "Bread", "price": 20, "unit": "pack"},
            "DY001":{"name": "Milk", "price":60, "unit": "liter"},
            "DY002":{"name": "Cheese", "price":700, "unit":"Kg"},
            "DY003":{"name": "Yogurt", "price":1200, "unit": "Kg"},
            "FR001":{"name": "Chips", "price": 20, "unit": "pack"},
            "FR002":{"name": "Popcorn", "price":30, "unit": "pack"}
        }

class cart(Database):
    def __init__(self):
        self.__cart = dict()
        
    
    def Add_item(self, id: str, quantity: int) -> None:
        if self.__cart.get(id, -1) == -1:
            self.__cart[id] = quantity
        else :
            self.__cart[id] += quantity
    
    def remove(self, id: str) -> None:
        del self.__cart[id]

class grocery(cart):
    def __init__(self, c_id, name):
        self.id = c_id
        self.name = name
    
    def gr_list(self):
        print("Name -->Rs. Per unit")
        for item in self.__items:
            print(item["name"],"-->", item["price"],"Per", item["unit"])

gr = grocery("xyz", "sfsfs")
gr.gr_list()