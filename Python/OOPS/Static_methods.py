# Static methods don't have self parameter and they work at class level

class Student:
    """Decorators Allows us to wrap another fucntion in order to
    extend the behaviour of the wrapped fucntion, without
    permanently modifying it."""
    @staticmethod #decorator
    def collage():
        print("PSIT")
    
s1 = Student()
s1.collage()