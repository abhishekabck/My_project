def solve():
    t = int(input())  # number of test cases
    for _ in range(t):
        n, m, q = map(int, input().split())  # n: deck size, m: initial position of the joker, q: number of operations
        a = list(map(int, input().split()))  # positions where cards are moved
        
        # Initially, joker can only be in position m
        left_bound = m
        right_bound = m
        
        result = []
        for i in range(q):
            move = a[i]
            if move <= left_bound:  # Joker's position could be affected by moving card to the front
                left_bound = move
            if move >= right_bound:  # Joker's position could be affected by moving card to the back
                right_bound = move
                
            # The number of distinct positions for the joker is from left_bound to right_bound
            result.append(right_bound - left_bound + 1)
        print("answer")
        print(" ".join(map(str, result)))

# Input reading
solve()
