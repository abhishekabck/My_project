def total_distance(test_cases):
    results = []
    for case in test_cases:
        n, a, b, c = case
        total = a+b+c
        days = 0
        if n >= total:
            days = (n//total)*3
            n = n%total
        if n > 0:
            n -= a
            days+=1
        if n > 0:
            n -= b
            days += 1
        if n > 0:
            n -= c
            days += 1
        results.append(days)
    return results

t, test_cases=int(input()), list()
for x in range(t):
    test_cases.append(tuple(map(int, input().split())))

results = total_distance(test_cases)
for x in results:
    print(x)