def solve():
    # Read the number of snakes and events
    n, q = map(int, input().split())
    
    # Initialize snake positions: Each snake starts in one cell.
    positions = [(i, i) for i in range(1, n + 1)]  # each snake starts at [i, i]
    
    # Process each event
    for _ in range(q):
        event = input().split()
        snake_id = int(event[0]) - 1  # Convert to zero-indexed
        operation = event[1]
        
        # Get current position of the snake
        l, r = positions[snake_id]
        
        if operation == "+":
            # Snake enlarges
            positions[snake_id] = (l, r + 1)
        elif operation == "-":
            # Snake shrinks
            positions[snake_id] = (l + 1, r)
    
    # Find the maximum position occupied after all events
    max_position = 0
    for l, r in positions:
        max_position = max(max_position, r)
    
    # Output the result
    print(max_position)

# Call the function to run the solution
solve()
