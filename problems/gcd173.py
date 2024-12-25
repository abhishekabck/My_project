class FenwickTree:
    def __init__(self, n):
        self.n = n
        self.tree = [0] * (n + 1)
    
    def update(self, idx, delta):
        while idx <= self.n:
            self.tree[idx] += delta
            idx += idx & -idx
    
    def query(self, idx):
        result = 0
        while idx > 0:
            result += self.tree[idx]
            idx -= idx & -idx
        return result
    
    def range_query(self, left, right):
        return self.query(right) - self.query(left - 1)

def solve():
    n = int(input())
    a = list(map(int, input().split()))
    q = int(input())
    
    last = 0
    fenwick = [FenwickTree(n) for _ in range(n + 1)]  # Fenwick trees for frequency of each number 1 to n
    
    # Initialize Fenwick Tree for the array a
    for i in range(n):
        fenwick[a[i]].update(i + 1, 1)

    def count_pairs(l, r):
        # Count total pairs: (r - l + 1) * (r - l) / 2
        total_pairs = (r - l + 1) * (r - l) // 2
        freq_map = {}
        
        # Get frequencies in range l to r
        for num in range(1, n + 1):
            freq = fenwick[num].range_query(l, r)
            if freq > 1:
                freq_map[num] = freq
        
        # Subtract invalid pairs (those where ai == aj)
        invalid_pairs = 0
        for count in freq_map.values():
            invalid_pairs += count * (count - 1) // 2
        
        return total_pairs - invalid_pairs
    
    for _ in range(q):
        # Decode the query
        t, *params = map(int, input().split())
        
        if t == 1:
            # Update query: decode p and x
            p_prime, x_prime = params
            p = ((p_prime + last) % n) + 1
            x = ((x_prime + last) % n) + 1
            old_val = a[p - 1]
            a[p - 1] = x
            # Update Fenwick Trees
            fenwick[old_val].update(p, -1)
            fenwick[x].update(p, 1)
        
        elif t == 2:
            # Count query: decode l and r
            l_prime, r_prime = params
            l = ((l_prime + last) % n) + 1
            r = ((r_prime + last) % n) + 1
            if l > r:
                l, r = r, l
            # Compute the answer for this query
            result = count_pairs(l, r)
            last = result
            print(result)
