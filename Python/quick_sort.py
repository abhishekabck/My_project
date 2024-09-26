def partition(array, low, high):
    if low<high:
        i,j = high, high
        pivot = array[low]
        while low<i:
            if array[i] >= pivot:
                array[i], array[j] = array[j], array[i]
                j -= 1
            i -= 1
        array[low], array[j] = array[j], array[low]
        return j

def quick_sort(array, low, high):
    if high > low:
        point = partition(array, low, high)
        quick_sort(array, low, point - 1)
        quick_sort(array, point+1, high)

def main():
    array = [6,3,5,3,4,7,4,6,34,64,2]
    quick_sort(array, 0, len(array)-1)
    print(array)
    

if __name__ == "__main__":
    main()