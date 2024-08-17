def min_doors_to_lock(l, r, L, R):
    if r < L:
        return L - r
    elif R < l:
        return l - R
    else:
        return 0

t = int(input())
for _ in range(t):
    l, r = map(int, input().split())
    L, R = map(int, input().split())
    print(min_doors_to_lock(l, r, L, R))
