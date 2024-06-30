def can_collect_coin(n, coins):
    results = []
    
    for x, y in coins:
        # Check if Monocarp can reach (x, y) in exactly y seconds
        if y >= 0 and abs(x) <= y:
            results.append("YES")
        else:
            results.append("NO")
    
    return results

# Read input
n = int(input())
coins = [tuple(map(int, input().split())) for _ in range(n)]

# Determine if Monocarp can collect each coin
results = can_collect_coin(n, coins)

# Print results
for result in results:
    print(result)
