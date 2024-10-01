n = int(input("Enter n:"))
odds = [str(i) for i in range(1,n,2)]
evens = [str(i) for i in range(2,n,2)]
print("".join(odds))
print("".join(evens))
