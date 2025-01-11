def optimal_merge(arr: list[int]):
    arr.sort()
    cost = list()
    i = 0
    while i < len(arr):
        if not cost:
            cost.append(arr[i] + arr[i+1])
            i+=1
        elif i < len(arr) - 1 and (arr[i] + arr[i+1]) < (arr[i] + cost[-1]):
            cost.append(arr[i]+arr[i+1])
            i+=1
        else:
            cost.append(arr[i]+cost[-1])
        i+=1
        print(cost,arr[i:],sep=" -><- ")
    return sum(cost)

arr = [4, 5, 3, 1, 2]
print("optimal Cost:- ", optimal_merge(arr))