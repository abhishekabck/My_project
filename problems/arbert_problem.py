import math
def print_divisibility(test_cases):
    for case in test_cases:
        result = [1]
        n, d = case
        if n >= 3 or d%3 == 0:
            result.append(3)
        if d == 5:
            result.append(5)
        if n > 2 or (n == 2 and d == 7):
            result.append(7)
        if n>5:
            result.append(9)
        else:
            factorial = math.factorial(n)
            if (factorial*d)%9 == 0:
                result.append(9)
        print(" ".join(map(str, result)))

t, test_cases = int(input()), list()
for _ in range(t):
    test_cases.append(list(map(int, input().split())))

print_divisibility(test_cases)
