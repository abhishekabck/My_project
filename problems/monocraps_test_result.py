def Monocraps_crap(test_cases):
    results = []
    for case in test_cases:
        n, m, k, ai, ki = case
        ki_set = set(ki)  # Convert ki to a set for efficient lookups
        if len(ki_set) < n - 1:
            results.append("0" * m)  # Directly append a string of "0"s
        else:
            result = []
            for x in ai:
                if x in ki_set and k < m:
                    result.append("0")  # Append to the list
                else:
                    result.append("1")
            results.append("".join(result))  # Join list into a string at the end
    return results

# Input parsing
t = int(input())
test_case = []
for _ in range(t):
    n, m, k = map(int, input().split())
    ai = tuple(map(int, input().split()))
    ki = tuple(map(int, input().split()))
    test_case.append((n, m, k, ai, ki))

# Solve the problem
results = Monocraps_crap(test_case)

# Print results
print("\n".join(results))
