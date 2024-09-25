#1. write a program to create a list in which elements are alphabet of your name and print first and second last elements of this list
#2. Iterate and print all the elements of this list using while loop

# name = "abhishek"
# ls = list(name)
# print(ls[-1], ls[-2])

# i = 0
# while i<len(ls):
#     print(ls[i])
#     i+=1

days = ["Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"]
print(len(days))
print(days[0], days[1])

# List slicing
print(days[:3])
print(days[-2:])


fruits = list()
fruits.append("apple")
fruits.append("banana")
fruits.append("mango")

more_fruits = ["orange", "grape"]
fruits.extend(more_fruits)
print(fruits)