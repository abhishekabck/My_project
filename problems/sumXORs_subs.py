class Solution:
    def usubset(self, subs, allsubs,l, idx):
        # Fucntion which calculates subset of unique length
        if l == len(subs):
            # using copy fucntion so on using pop fucntion subs does not modify in allsubs list
            allsubs.append(subs.copy())
            return
        elif idx >= len(self.nums):
            return
        subs.append(self.nums[idx])
        self.usubset(subs, allsubs,l, idx+1)
        subs.pop()
        self.usubset(subs, allsubs,l, idx+1)

    def subsetXORSum(self, nums: list[int]) -> int:
        # initializing nums so it can be accessd to every fucntion
        self.nums = nums
        

        
        