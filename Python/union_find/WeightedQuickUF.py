class WeightedQuickUnionFind :
    def __init__(self, n):
        self.parent = list(range(n))
        self.size = [1 for i in range(n)]
        self.count = n
    
    # returns Number of sets
    def count(self):
        return self.count
    
    def validate(self, p) -> None:
        n = len(self.parent)
        if p<0 or p>= n:
            raise ValueError.add_note("Index " + str(p) + " is not between 0 and " + str((n - 1)))
        
        
        
    def find(self, p) -> int:
        self.validate(p)
        while (self.parent[p] != p):
            p = self.parent[p]
        return p
    
    def connected(self, p, q) -> bool:
        return self.find(p) == self.find(q)
    
    def union(self, p, q):
        self.validate(p)
        self.validate(q)
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

if __name__ == "__main__":
    wuf = WeightedQuickUnionFind(10)
    wuf.union(5, 6)
    wuf.union(4, 8)
    wuf.union(5, 4)
    wuf.union(1, 5)
    print(wuf.find(5))