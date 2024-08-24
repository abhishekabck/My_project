class Car: # Parent class
    @staticmethod
    def start():
        print("Car Started")
    
    @staticmethod
    def stop():
        print("Car Stopped..")

class ToyotaCar(Car): # child of car or parent of Fortuner
    def __init__(self, brand):
        self.name = brand

class Fortuner(ToyotaCar): # child of ToyotaCar
    def __init__(self, type):
        self.type = type

car1 = Fortuner("Diesel")
car1.start()
