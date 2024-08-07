class WeightedQuickUnionFind :
    def __init__(self, n):
        self.parent = list(range(n))
        self.size = [1 for i in range(n)]
        self.count = n
    
    # returns Number of sets

    def find(self, p) -> int:
        while (self.parent[p] != p):
            p = self.parent[p]
        return p
    
    def connected(self, p, q) -> bool:
        return self.find(p) == self.find(q)
    
    def union(self, p, q):
        rootp = self.find(p)
        rootq = self.find(q)
        if rootp != rootq :
            if self.size[rootp] < self.size[rootq]:
                self.parent[rootp] = rootq
                self.size[rootq] += self.size[rootp]
            else :
                self.parent[rootq] = rootp
                self.size[rootp] += self.size[rootp]

            self.count -= 1

class Solution:
    def findCircleNum(self, isConnected: list[list[int]]) -> int:
        n = len(isConnected)
        wuf = WeightedQuickUnionFind(n)
        for i in range(n):
            for j in range(i+1, n):
                if isConnected[i][j] == 1:
                    wuf.union(i,j)
        
        return wuf.count
    
print(Solution().findCircleNum([[1,0,0],[0,1,0],[0,0,1]]))