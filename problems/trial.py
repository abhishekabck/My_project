from typing import List
class Solution:
    def longestMonotonicSubarray(self, nums: List[int]) -> int:
        i, j, n = 1, -1, len(nums)
        sti = 0
        std = 0
        result = 0
        while i < n or j > -n:
            if nums[i-1] < nums[i]:
                sti += 1
                i+=1
            elif nums[i-1] >= nums[i]:
                result = max(result, sti)
                sti = 0
                i+=1
            if nums[j-1] > nums[j]:
                std += 1
                j -= 1
            elif nums[j-1] <= nums[j]:
                result = max(result, std)
                std = 0
                j-=1
        print(result)
        return result
Solution().longestMonotonicSubarray([3,2,1])