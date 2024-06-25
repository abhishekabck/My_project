import mysql.connector as mq

class db_grocery:
    def __init__(self):
        self.db = mq.connect(user = "root",host = "localhost", password = "5844",port = 3306,database = "director")
        self.cur = self.db.cursor()
        self.items = []
        self.cart = {}
        self.ls = []
        
    def _item_list(self):
        db.cur.execute("select item_name,unit,price from grocery_items")
        ilist = list(db.cur)
        return ilist
    
    def _cart(self):
        self.item_pair = self.item_list()
        db.cur.execute("Select Item_Code,0 from grocery_items")
        self.cart.update(list(db.cur.execute))
    
    
    def Total(self):
        sum = 0
        self.cur.execute("Select item_code,price from grocery_items")
        self.ls.extend(list(self.cur))
        for index in range(len(self.ls)):
            sum = sum + self.ls[index][1] * self.cart[self.ls[index][0]]
        return sum
    
    
    def display_cart(self):
        print("Item List is as follows:- ")
        print("||  Item_code  ||  Item_name   ||  Stock   ||")
        j = 0
        for i in self.cart:
            if self.cart[i] != 0:
                print(f"||  {i}   || {self.items[j][0]}    ||  {self.cart[i]}  ||")
            j+=1
    
    def checkout(self):
        if 1:
            print("Payment Successfull")
            query = "INSERT INTO sold_items (ITEM_NO,N_STOCK) values"
            for tup in db.cart.items():
                query += str(tup) + ", "
            db.cur.execute(query)
            
        
        


db = db_grocery()
db.items.extend(db._item_list())
    

def main():
    print("  -->>Welcome to Grocery Shop<<--")
    print("  -->> Pick Your Choice-->>\n1. Add Item to Cart (Select Items):\n2. Display Cart/ (Check Items)\n3. Ckeckout Cart (Buy all):\n4. Exit:")
    ch = int(input("  --> Choice :- "))
    if ch == 1:
        Add_item()
        
    elif ch == 2:
        db.display_cartplay()
        
    elif ch == 3:
        db.checkout()
        
    elif ch == 4:
        if db.Total() != 0 :
            print("There are Still remaining items in your Cart Do you still wish to Leave(Yes/No)\nOn Selecting Yes all items from cart will be retrivied.")
            _c = input("Choice || (Yes/No):- ")
            if (_c.lower() == "yes") :
                exit()
            else:
                db.checkout()
    
    
def Add_item():
        print("   ->>Item list:-")
        # To Print The all items available from database
        for ind in range(len(db.items)):
            item = db.items[ind]
            print(f"{ind+1}. {item[0]} per Package: {item[1]} {item[2]}/-")
        choice = int(input("Choosen Item No. :- "))
        stock = int(input("Enter No of Package: minimum = 1 "))
        db.cart[db.ls[choice-1][0]] += stock
        print("Item added Successfully in Cart")
        print("-- > Menu (Default):-\n1.Return to main menu:\n2. Add More items to cart\n3. Checkout cart")
        _ch = int(input("Choice:-"))
        if _ch == 1:
            main()
        elif _ch == 2:
            Add_item()
        elif _ch == 3:
            db.checkout()
        else :
            print("Wrong Choice\n")
            main()
        
            
         
        


if __name__ == "__main__": 
    main()