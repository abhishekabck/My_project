from typing import List
class Solution:
    def sumOfGoodNumbers(self, nums: List[int], k: int) -> int:
        n = len(nums)
        s = 0
        for i in range(n):
            is_good = True
            for j in range(i-k, i+k+1, 1):
                if j < 0 or j >= n:
                    continue
                if nums[j] >= nums[i]:
                    is_good = False
                    break
            if is_good:
                s += nums[i]
            print(nums[i], is_good)
        return s
print(Solution().sumOfGoodNumbers([1,3,2,1,5,4], 2))