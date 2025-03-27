def solve():
    t = int(input())
    for i in range(t):
        l, r, d, u = list(map(int, input().split()))
        print("YES" if (l == r == d == u) else "NO")

solve()