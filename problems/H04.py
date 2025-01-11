def coffee_break(t, test_cases):
    results = []
    for case in test_cases:
        n, students = case
        max_students = students[:]
        
        for i in range(1, n+1):
            current_students = students[:]
            while True:
                new_students = current_students[:]
                for j in range(1, n+1):
                    if current_students[j-1] > 0:
                        half = current_students[j-1] // 2
                        new_students[j-1] -= 2 * half
                        if j > 1:
                            new_students[j-2] += half
                        if j < n:
                            new_students[j] += half
                if new_students == current_students:
                    break
                current_students = new_students
            max_students[i-1] = max(max_students[i-1], current_students[i-1])
        
        results.append(max_students)
    
    return results

# Example usage:
t = 3
test_cases = [
    (2, [8, 0]),
    (5, [2, 2, 2, 2, 2]),
    (5, [0, 0, 9, 0, 0])
]

results = coffee_break(t, test_cases)
for result in results:
    print(" ".join(map(str, result)))
