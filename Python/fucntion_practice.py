# With Some arguments and No Returns
def print_name(firstname, lastname):
    print(firstname + " " + lastname)

# With Some arguments and Some Returns
def print_namer(firstname, lastname):
    return firstname + " " + lastname

# With No Arguments and No returns
array = [2,3,4,5,64,323]
def Traverse():
    for i in array:
        print(i,end = ", ")

# With No Arguments and Some Returns
def find3():
    key = 3
    low, high = 0, len(array) - 1
    while low<=high:
        mid= low + (high - low)//2
        if array[mid] == key:
            return mid
        elif array[mid]>key:
            high = mid - 1
        else :
            low = mid + 1
    
    return -1

print_name("Abhishek", "Chaurasiya")
print(print_namer("Abhi", "Chay"))
Traverse()
print("\n",find3())