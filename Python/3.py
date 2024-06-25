# Factorial of a Number.

num = int(input("Enter number:-"))
fact = 1
for i in range(num):
    fact = fact*(i+1)
print("Factorial:-",fact)