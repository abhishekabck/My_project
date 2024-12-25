import bisect

class Solution:
    def findLengthOfShortestSubarray(self, arr) -> int:
        l1, l2 = [arr[0]], [arr[-1]]
        for x in range(1, len(arr)):
            if l1[-1] <= arr[x]:
                l1.append(arr[x])
            else:
                break
        
        for x in range(len(arr) - 2, -1, -1):
            if l2[-1] >= arr[x]:
                l2.append(arr[x])
            else:
                break
        l2 = list(reversed(l2))
        rem = len(arr) - len(l2)
        result = len(arr)
        for i in set(l1):
            x = bisect.bisect_right(l1, i)
            y = bisect.bisect_left(l2, i)
            result = min(result, rem + y - x)
        return result


print(Solution().findLengthOfShortestSubarray([1,2,3,10,4,2,3,5]))
