import heapq

def solve():
    t = int(input())
    for _ in range(t):
        n = int(input())
        pq = []
        for i in map(int, input().split()):
            heapq.heappush(pq, i)
        while len(pq) > 1:
            x = heapq.heappop(pq)
            y = heapq.heappop(pq)
            heapq.heappush(pq, x + y - 1)
        print(heapq.heappop(pq))

solve()