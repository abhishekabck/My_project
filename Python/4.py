# Fibonacci Series up to N terms.

n = int(input("Enter number of times you wish to print fabonacci series:-"))
n1,n2,n12=0,1,0
print(n1,",",n2)
for i in range(n-2):
    n12 = n1 + n2
    n1 = n2
    n2 = n12
    print(",",n12,end="",sep="")
