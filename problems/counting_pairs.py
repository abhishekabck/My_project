# def total_pairs(test_cases):
#     results = []
#     for case in test_cases:
#         n, x, y, a = case
#         total = sum(a)
#         # edge cases
#         if total < x:
#             results.append(0)
#         else:
#             prefix_sum = [a[0]]
#             for i in range(1, len(a)):
#                 prefix_sum.append(prefix_sum[i-1]+a[i])
            


# t, test_cases = int(input()), list()
# for x in range(t):
#     n, x, y = map(int, input().split())
#     a = list(map(int, input().split()))
#     test_cases.append([n,x,y,a])

from bisect import bisect_left, bisect_right

def count_interesting_pairs(test_cases):
    results = []
    for n, x, y, a in test_cases:
        S = sum(a)
        target_min = S - y
        target_max = S - x
        
        # Sort the array
        a.sort()
        count = 0
        
        for i in range(n):
            # Find range [target_min - a[i], target_max - a[i]]
            lower = bisect_left(a, target_min - a[i], i + 1)
            upper = bisect_right(a, target_max - a[i], i + 1) - 1
            count += max(0, upper - lower + 1)
        
        results.append(count)
    return results

# Input parsing
t = int(input())
test_cases = []

for _ in range(t):
    n, x, y = map(int, input().split())
    a = list(map(int, input().split()))
    test_cases.append((n, x, y, a))

# Solve the problem
results = count_interesting_pairs(test_cases)

# Output results
print("\n".join(map(str, results)))
