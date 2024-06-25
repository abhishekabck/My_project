# Sum and average of n Natural Numbers .

n = int(input("Enter number of numbers you wish to enter:-"))
sum = 0
for i in range(n):
    temp = int(input("Enter number:-"))
    sum+=temp
print("Sum of numbers:-",sum)
print("Average of numbers:-",sum/n)