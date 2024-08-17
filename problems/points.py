def solve():
    t = int(input())
    results = []
    
    for _ in range(t):
        n = int(input())
        points = list(map(int, input().split()))
        
        # Check the minimum distance between consecutive points
        min_distance = min(points[i+1] - points[i] for i in range(n-1))
        
        if min_distance > 1:
            results.append("YES")
        else:
            results.append("NO")
    
    print("\n".join(results))

# Call the solve function to execute
solve()
