class Solution:
    def minimumOperations(self, nums: List[int]) -> int:
        freq = Counter(nums)
        while len(set(nums)) == len(nums):
            if len(nums) < 3:
                return []
            nums = nums[2:]
        return nums

