import math

x = 70
y = 60
t = range(0, 90+1)

a = x/2
b = y

for i in t:
    xa, ya = round(a*math.cos(i), 0), round(b*math.sin(i), 0)
    print(xa, ya)