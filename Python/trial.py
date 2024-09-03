class Solution:
    def helper(self, ls, br, idx):
        if len(br) == len(ls):
            self.score = max(self.score, sum(br))
            return
        for i in ls[idx]:
            if i not in br:
                br.append(i)
                self.helper(ls, br, idx+1)
                br.pop()
        
    def maxScore(self, grid: list[list[int]]) -> int:
        self.score = 0
        self.helper(grid, [], 0)
        return self.score
        
print(Solution().maxScore([[5],[7],[19],[5]]))