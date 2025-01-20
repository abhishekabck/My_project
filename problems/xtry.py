class Solution:
    def firstCompleteIndex(self, arr: list[int], mat: list[list[int]]) -> int:
        m, n = len(mat), len(mat[0])
        freq = {}
        result = [0]*(m+n)
        # storing frequency
        for i in range(m):
            for j in range(n):
                freq[mat[i][j]] = (i, j,)
        for x in range(len(arr)):
            i, j = freq[arr[x]]
            result[i] += 1
            result[j+m] += 1
            if result[i] == n:
                return x
            if result[j+m] == m:
                return x
        return 1
        
print(Solution().firstCompleteIndex([1,4,5,2,6,3], [[4,3,5],[1,2,6]]))