Example = [
    ([1, 53, 23, 5, 243, 55], [4, 2, 44, 653, 32, 64])
]

array1 = Example[0][0]
array2 = Example[0][1]


def Sorted_array(arr1, arr2):
    size1, size2 = len(arr1), len(arr2)
    result = [float('-inf')]
    size3 = size1 + size2
    while len(result) <= size3:
        minimum = float('inf')
        flag = True
        for i in range(size1):
            if arr1[i] < minimum and arr1[i] > result[-1]:
                minimum = arr1[i]
                flag = False
        for j in range(size2):
            if arr2[j] < minimum and arr2[j] > result[-1]:
                minimum = arr2[j]
                flag = False
        if flag:
            break
        result.append(minimum)
    return result[1:]

print(Sorted_array(array1, array2))
