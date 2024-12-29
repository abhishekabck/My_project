def solve_cocoly_problem(test_cases):
    results = []
    
    for n, a in test_cases:
        a.sort()
        # Case 1: If all elements are the same, there is only one way to partition.
        if len(set(a)) == 1:
            results.append("NO")
            continue

        # Case 2: Check if the array can be a single stable set
        if a[-1] >= a[-2] + a[-3]:
            # Largest element is too big; the array cannot be a single stable segment
            results.append("YES")
        else:
            # Check if there's another valid partition (split at any index)
            # E.g., [a[0:k], a[k:n]] where both are stable
            results.append("YES")
    
    return results


# Input parsing and execution
def main():
    t = int(input("Enter the number of test cases: "))
    test_cases = []
    
    for _ in range(t):
        n = int(input("Enter the length of the array: "))
        a = list(map(int, input("Enter the array elements: ").split()))
        test_cases.append((n, a))
    
    results = solve_cocoly_problem(test_cases)
    for result in results:
        print(result)


# Call the main function
main()
