n, m, q = map(int, input().split())
queries = [input().split() for _ in range(q)]
queries = [(int(x) - 1, int(y) - 1, c) for x, y, c in queries]

row_constraints = {}
column_constraints = {}
total_row_paints = 0
total_column_paints = 0

results = []

for xi, yi, ci in queries:
    # Update row constraints
    if xi in row_constraints:
        old_color = row_constraints[xi]
        if old_color == ci:
            results.append(total_row_paints ** 2 + total_column_paints ** 2)
            continue
    else:
        total_row_paints += 1
    
    row_constraints[xi] = ci

    # Update column constraints
    if yi in column_constraints:
        old_color = column_constraints[yi]
        if old_color == ci:
            results.append(total_row_paints ** 2 + total_column_paints ** 2)
            continue
    else:
        total_column_paints += 1
    
    column_constraints[yi] = ci

    results.append(total_row_paints ** 2 + total_column_paints ** 2)

# Output all results
for result in results:
    print(result)
