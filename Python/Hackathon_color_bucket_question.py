class processing(object):
    def __init__(self, rows, columns):
        self.rows = rows   # total number of rows in colored matrix
        self.columns = columns # total number of columns in colored matrix
        
    def cv(self, co):       # returns the color value of any co-ordinates
        return bucket[co[0]][co[1]]
    
    def adrs(self, co):       # return Address of any co-ordinate
        for i in range(len(s)):
            for j in range(len(s[i])):
                if s[i][j] == co:
                    return (i,j)
                
    def up_a_right(self, co, y, x):         # to find and add currrent cv to belonging one from upwward-right
        if self.cv((y, x)) == self.cv((y-1, x)):
            i, j = self.adrs((y-1, x))
            s[i].append(co)
        else :
            c = False
            for i in range(co[1]+1, self.columns):
                if self.cv((co[0], i)) == self.cv(co):
                    if self.cv(co) == self.cv((co[0]-1, i)):
                        i, j = self.adrs((co[0]-1, i))
                        s[i].append(co)          # if upward value in right side is founded
                        break
                else :
                    c = True            # signifies result of searching Future right upward value
            if c:
                s.append([co])      # if Right upward value is not founded
                
    def movements(self, co):
        y = co[0]
        x = co[1]
        if (x-1)>=0 :               # to check backward movement possibility
            if self.cv((y, x)) == self.cv((y, x-1)):    # to check backward and current values are equal or not
                i, j = self.adrs((y, x-1))
                s[i].append(co)
                
            elif (y-1)>=0:
                self.up_a_right(co, y ,x)
                
            else :
                s.append([co])
    
        elif (y-1)>=0 : # to check upward movement possibility
            self.up_a_right(co, y, x)
    
        else :
            s.append([co])
        
        
        
if __name__=="__main__":
    a = "aaabb babaa bbbab"              # Input format --->>aabab abbaa abbba<<----
    bucket = list(map(str, a.split()))   # list contating all colors seperated by comma's 
    ty = len(bucket)
    tx = len(bucket[0])
    s = [] # strokes
    pr = processing(ty, tx)
    for y in range(ty):
        for x in range(tx):
            co = (y, x)
            pr.movements(co)
    print("No of Strokes :-",len(s))
            