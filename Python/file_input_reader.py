with open(r"C:\Users\Public\Documents\Projects\Python\x.txt") as file:
    N = int(file.readline())
    for i in range(N):
        a,b = tuple(map(int, file.readline().split()))
        print(a+b)