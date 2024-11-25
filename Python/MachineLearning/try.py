from typing import List

class Solution:
    def maximumSubarraySum(self, nums: List[int], k: int) -> int:
        psum = sum(nums[:k])
        msum = 0
        for i in range(len(nums)-k):
            if len(set(nums[i:i+k])) == k:
                msum = max(psum, msum)
            psum -= nums[i]
            psum += nums[i+k]
        if len(set(nums[-k:])) == k:
            msum = max(psum, msum)
        return msum


print(Solution().maximumSubarraySum([1,1,1,7,8,9], 3))