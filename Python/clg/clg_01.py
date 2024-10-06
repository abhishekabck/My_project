# n = int(input("Enter n:"))
# odds = [str(i) for i in range(1,n,2)]
# evens = [str(i) for i in range(2,n,2)]
# print("".join(odds))
# print("".join(evens))

# tup = tuple(eval(input("Enter the Data:")))
# print(f"Sum:- {sum(tup)}")
# print(f"Average:- {sum(tup)/len(tup)}")

# Write a Program to take input of your name and insert all the characters of your name in a Tuple
# name = input("Enter Your Name:")
# tup = tuple()
# for i in name:
#     if i.isalpha():
#         tup += (i,)
# print(tup)

# write a fun that takes a string as input and returns the string with all vowels converted to uppercase and all consonents in lower case
string = input("Enter Your String::")
newString = ""
for i in string:
    if i.lower() in "aeiou":
        newString += i.upper()
    elif i.isalpha():
        newString += i.lower()
    else:
        newString += i
print(newString)
