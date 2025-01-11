def solve(n, m):
    print(max(n,m) + 1)
t = int(input())
for i in range(t):
    n, m  = map(int, input().split())
    solve(n, m)