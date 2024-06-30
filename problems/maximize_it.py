def maximize_modulo_sum(lists, m):
    k = len(lists)
    # Initialize a set with a single element 0
    possible_values = {0}
    
    for lst in lists:
        current_values = set()
        for value in lst:
            square_mod_m = (value ** 2) % m
            for current in possible_values:
                new_value = (current + square_mod_m) % m
                current_values.add(new_value)
        possible_values = current_values
    
    # The result is the maximum value in the possible_values set
    return max(possible_values)

# Example usage:
k = 3  # Number of lists
m = 1000  # Modulo value
lists = [
    [2, 5, 8],
    [3, 7, 9],
    [1, 4, 6]
]

result = maximize_modulo_sum(lists, m)
print(result)  # Output will be the maximized value
