class Solution:
    def hourglass(self, ind : tuple[int] , grid: list[list[int]]):
        fl = grid[ind[0]][ind[1]] + grid[ind[0]][ind[1] + 1] + grid[ind[0]][ind[1] + 2]
        ll = grid[ind[0] + 2][ind[1]] + grid[ind[0] + 2][ind[1] + 1] + grid[ind[0] + 2][ind[1] + 2]
        return fl + grid[ind[0] + 1][ind[1] + 1] + ll


    def maxSum(self, grid: list[list[int]]) -> int:
        m = len(grid)
        n = len(grid[0])
        Sum = self.hourglass((0,0), grid)
        for i in range(1, m - 2):
            for j in range(n - 2):
                Sum = max(self.hourglass((i, j,) , grid), Sum)
        return Sum
    
inp1 = [[6,2,1,3],[4,2,1,5],[9,2,8,7],[4,1,2,9]]
inp2 = [[1,2,3],[4,5,6],[7,8,9]]
inp3 = [[520626,685427,788912,800638,717251,683428],
        [23602,608915,697585,957500,154778,209236],
        [287585,588801,818234,73530,939116,252369]]

c1 = Solution()
print(c1.maxSum(inp3))
