# super() method is used to access methods of the parent class.
class Car:
    def __init__(self, typ):
        self.type = typ
    
    @staticmethod
    def start():
        print("Car Started..")
    
    @staticmethod
    def stop():
        print("Car Stopped..")

class ToyotaCar(Car):
    def __init__(self, name, typ):
        super().__init__(typ)
        self.name = name

car1 = ToyotaCar("pirus", "electric")
print(car1.type)

