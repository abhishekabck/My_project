class x:
    @staticmethod
    def s1():
        print("x")


class y:
    @staticmethod
    def s2():
        print("y")

class z(x,y):
    @staticmethod
    def s3():
        print("z")


z.s1()
z.s2()
z.s3()
