# PRime number in range.
start = int(input("Enter starting range:-"))
end = int(input("Enter ending range:-"))

for i in range(start,end):
    for j in range(2,i):
        if i%j==0:
            print(i,"Is Not Prime numeber.")
            break
    