class Solution:
    def updateMatrix(self, mat: list[list[int]]) -> list[list[int]]:
        n = len(mat)
        m = len(mat[0])
        result = []
        for i in range(n):
            result.append(list())
            for j in range(m):
                result[i].append(0)
        if (mat[0][0] != 0):
            result[0][0] = m+n

        ### Part -1 
        # Going through first row
        for i in range(1, m):
            if mat[0][i] == 0:
                result[0][i] = 0
            else:
                result[0][i] = result[0][i-1] + 1
        
        # going through first column
        for i in range(1, n):
            if mat[i][0] == 0:
                result[i][0] = 0
            else:
                result[i][0] = result[i-1][0] + 1
        
        # Traversing right down 
        for i in range(1, n):
            for j in range(1, m):
                result[i][j] = min(result[i-1][j] + 1, result[i][j-1] + 1) if mat[i][j] != 0 else 0
        

        ### Part- 2
        result2 = list()
        for i in range(n):
            result2.append(list())
            for j in range(m):
                result2[i].append(0)
        result2[n-1][m-1] = m+n
        if mat[n-1][m-1] == 0:
            result2[n-1][m-1] = 0
        
        for i in range(n-2, -1, -1):
            result2[i][m-1] = result2[i+1][m-1] + 1 if mat[i][m-1] != 0 else 0

        for i in range(m-2, -1, -1):
            result2[n-1][i] = result2[n-1][i+1] + 1 if mat[n-1][i] != 0 else 0
        
        # Traverse left up
        for i in range(n-2, -1, -1):
            for j in range(m-2, -1, -1):
                result2[i][j] = min(result2[i+1][j] + 1, result2[i][j+1] + 1) if mat[i][j] != 0 else 0

        print(result)
        print(result2)
        
        ## Merging of answers
        for x in range(n):
            for y in range(m):
                result[x][y] = min(result[x][y], result2[x][y])
        return result
            
print(Solution().updateMatrix([[0],[0],[0],[0],[0]]))