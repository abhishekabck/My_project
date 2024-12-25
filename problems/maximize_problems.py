def maximize_difference(t, test_cases):
    result = list()
    for case in test_cases:
        n, a, b = case
        x = [a[i]-b[i+1] for i in range(n-1) if (a[i]-b[i+1]>0)]
        x.append(a[-1])
        result.append(sum(x))
    return result


# Reading Input
t = int(input())
test_cases = []
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    test_cases.append((n, a, b))

# Calculating results
results = maximize_difference(t, test_cases)

# Output results
for result in results:
    print(result)
