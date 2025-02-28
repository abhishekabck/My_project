Example = [
    ([1, 53, 23, 5, 23, 5], [4, 2, 4, 53, 32, 64])
]

def merge_without_duplicates(arr1, arr2):
    result = []
    i = 0
    j = 0
    if arr1[0] < arr2[0]:
        result.append(arr1[0])
        i+=1
    else:
        result.append(arr2[0])
        j+=1
    while i < len(arr1) and j < len(arr2):
        if arr1[i] < arr2[j]:
            if result[-1] != arr1[i]:
                result.append(arr1[i])
            i+=1
        elif arr1[i] > arr2[j]:
            if result[-1] != arr2[j]:
                result.append(arr2[j])
            j += 1
        else:
            if result[-1] != arr1[i]:
                result.append(arr1[i])
            i += 1
            j += 1
    
    while i < len(arr1):
        if result[-1] != arr1[i]:
            result.append(arr1[i])
        i+=1
    while j < len(arr2):
        if result[-1] != arr2[j]:
            result.append(arr2[j])
        j+=1
    return result

def merge(array, low, mid, high):
    arr1 = []
    arr2 = []
    for i in range(mid - low + 1): arr1.append(array[i + low])
    for j in range(high - mid): arr2.append(array[j + mid + 1])
    i = 0
    j = 0
    k = 0
    while i < len(arr1) and j < len(arr2):
        if arr1[i] < arr2[j]:
            array[k + low] = arr1[i]
            i+=1
        else:
            array[k + low] = arr2[j]
            j += 1
        k+=1
    while i < len(arr1):
        array[k + low] = arr1[i]
        i+=1
        k+=1
    while j < len(arr2):
        array[k+low] = arr2[j]
        j+=1
        k+=1
    del arr1
    del arr2

def merge_sort(array, low,high):
    if low < high:
        mid = (low+high)//2
        merge_sort(array, low, mid)
        merge_sort(array, mid+1, high)
        merge(array, low, mid, high)

def main():
    arr1 = Example[0][0]
    arr2 = Example[0][1]
    merge_sort(arr1, 0, len(arr1) - 1)
    merge_sort(arr2, 0, len(arr2) - 1)
    print(arr1, arr2)
    result = merge_without_duplicates(arr1, arr2)
    print(result)
    
if __name__ == "__main__":
    main()