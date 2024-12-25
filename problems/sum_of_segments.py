def solve():
    t = int(input())  # Number of test cases
    for _ in range(t):
        n = int(input())  # Size of the array
        a = list(map(int, input().split()))  # The array elements
        
        # To store all distinct subarray sums
        distinct_sums = set([0])  # We start with the empty subarray sum
        
        # Variable to store the prefix sum
        prefix_sum = 0
        
        # Iterate over the array and calculate prefix sums
        for num in a:
            prefix_sum += num
            distinct_sums.add(prefix_sum)
        
        # Convert the set to a sorted list
        distinct_sums = sorted(distinct_sums)
        
        # Print the number of distinct sums and the sums themselves
        print(len(distinct_sums))
        print(" ".join(map(str, distinct_sums)))

# Example usage
solve()
