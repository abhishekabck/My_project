def max_earnings(t, test_cases):
    results = []
    for n, k, a, b in test_cases:
        customers = sorted(zip(a, b), key=lambda x: x[0])
        a_sorted = [x[0] for x in customers]
        b_sorted = [x[1] for x in customers]
        
        total_earnings = sum(a_sorted)  # Initial earnings with all positive reviews
        negative_review_costs = []
        
        # Calculate the "cost" of allowing negative reviews
        for i in range(n):
            cost = b_sorted[i] - a_sorted[i]
            negative_review_costs.append(cost)
        
        # Sort the costs to prioritize smallest "costly" negative reviews
        negative_review_costs.sort(reverse=True)
        
        # Add up to k most "costly" reviews to maximize earnings
        for i in range(k):
            if negative_review_costs:
                total_earnings += negative_review_costs.pop()
        
        results.append(total_earnings)
    
    return results

# Input parsing
t = int(input())
test_cases = []
for _ in range(t):
    n, k = map(int, input().split())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    test_cases.append((n, k, a, b))

# Solve the problem
results = max_earnings(t, test_cases)

# Output results
print("\n".join(map(str, results)))
