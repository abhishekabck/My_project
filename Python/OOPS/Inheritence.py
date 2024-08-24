# When one class(child/derived) derives the properties & methods of another class(parent/base).
"""Types:
1. Single Inheritence
2. Multi-level Inheritence
3. Multiple Inheritence
"""
class Car:
    color = "Black"
    @staticmethod
    def start():
        print("Car Started")
    
    @staticmethod
    def stop():
        print("Car Stopped..")

class ToyotaCar(Car):
    def __init__(self, name):
        self.name = name

car1 = ToyotaCar("fortuner")
car2 = ToyotaCar("Prius")
car1.start()
print(car1.color)

