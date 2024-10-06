class UF:
    def __init__(self, n) ->classmethod:
        self.n = n
        if (n < 0):
            raise ValueError.add_note("The number of entry should be greater than 0")
        self.count = self.n
        self.parent = [i for i in range(self.n)] # Declaring fixed size parent arrays
        self.rank = [0 for i in range(self.n)] # Declaring fixed size root arrays
    
    def find(self,p) -> int:
        n = len(self.parent)
        if (p < 0 or p>= n):
            raise ValueError.add_note("Index " + str(p) +" is not between 0 and " + str(n - 1))
        while (p!= self.parent[p]):
            self.parent[p] = self.parent[self.parent[p]] # Path Compresion
            p = self.parent[p]
        return p
    
    def count(self) -> int:
        return self.count
    
    def connected(self, p, q) -> bool:
        return self.find(p) == self.find(q)
    
    def union(self, p, q) -> None:
        rootp = self.find(p)
        rootq = self.find(q)
        if (rootp == rootq):
            return None
        
        if (self.rank[rootp] < self.rank[rootq]):
            self.parent[rootp] = rootq
        elif (self.rank[rootp] > self.rank[rootq]):
            self.parent[rootq] = rootp
        else:
            self.parent[rootq] = rootp
            self.rank[rootp] += 1
        self.count -= 1

invocations = [[1,2],[0,1],[3,2]]
k = 0
n = 4

def main(invocations, k, n):
    uf = UF(n)
    for ai, bi in invocations:
        uf.union(ai, bi)
    
    roots = dict()
    for i in range(0, n):
        rt = uf.find(i)
        if roots.get(rt, -1) == -1:
            roots[rt] = [i]
        else:
            roots[rt].append(i)
    answer = []
    for i in roots:
        if k not in roots[i]:
            answer.extend(roots[i])
    
    print(answer)
        

if __name__ == "__main__":
    main(invocations, k, n)