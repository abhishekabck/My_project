class women_info:
    def __init__(self,breast, height, weight, waist, Name):
        self.breast = breast
        self.height = height
        self.weight = weight
        self.waist = waist
        self.name = Name
        
class women_struct:
    def figure(self,breast,waist):
        ratio = breast/waist
        if (ratio>1.3):
            return "Super Sexy"h
        elif (ratio > 1.2):
            return "Sexy"
        elif ratio>1.1:
            return "Ok"
        elif ratio<1:
            return "flat"

s = women_info(106, 165, 55, 67, "Tsunade")
s1 = women_struct()
print(s1.figure(s.breast,s.waist))

