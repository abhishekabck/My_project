class Solution:
    def usubset(self, subs:list[int], allsubs : list[list[int]],l:int, idx:int) -> None:
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
    
    def subsets(self, nums : list[int]) -> list[list[int]]:
        # fucntion which provides the length for which a subset is required
        self.nums = nums
        allsubs = list()
        for l in range(len(nums)+1):
            self.usubset([], allsubs, l, 0)
        return allsubs

