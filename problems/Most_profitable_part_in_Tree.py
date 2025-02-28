edges1 = [[0,1],[1,2],[1,3],[3,4]]
bob1 = 3
amount1 = [-2,4,2,-4,6]

edges = [[0,2], [0,6], [1,3], [1, 5], [2, 5], [4, 6]]
bob = 6
amount = [8838, -6396, -5940, 2694, -1366, 4616, 2966]

from collections import deque

# def maximum_alice_earn(adj_grid: list[list[int]], amount: list[int], source: int, leaf_nodes: set[int]):
#     n = len(adj_grid)
#     visited = [False]*n
#     income_steps = [[0, 0] for i in range(n)]
#     income_steps[source] = [amount[source], 0]
#     stack = [source]
#     while stack:
#         node = stack.pop()
#         if not visited[node]:
#             visited[node] = True
#             for w in range(n):
#                 if adj_grid[node][w] != 0 and not visited[w]:
#                     stack.append(w)
#                     income_steps[w][0] = income_steps[node][0] + amount[w]
#                     income_steps[w][1] = income_steps[node][1] + 1
#     return income_steps

# def main():
#     n = len(amount)
#     adj_grid = [[0]*n for i in range(n)]
#     # Processing Edges to make adj Matrix(Grid)
#     leaf_nodes = set(range(n))
#     for x, y in edges:
#         if x in leaf_nodes:
#             leaf_nodes.remove(x)
#         adj_grid[x][y] += 1
#         adj_grid[y][x] += 1
#     alice_insteps = maximum_alice_earn(adj_grid, amount, 0, leaf_nodes)
#     bob_insteps = maximum_alice_earn(adj_grid, amount, bob, {0})
print()

"""Approach: - 2 """

def update_levels(grid, n):
    levels = [-1]*n
    parent_level = 0
    queue = deque([0])
    while queue:
        size = len(queue)
        for x in range(size):
            u = queue.popleft()
            levels[u] = parent_level
            for i in range(n):
                if grid[u][i] != 0 and levels[i] == -1:
                    queue.append(i)
        parent_level += 1
    return levels

def dfs_bob_steps(grid: list[list[int]],levels, bob_source):
    steps = [-1]*len(grid)
    stack = [bob_source]
    step = 0
    while stack:
        u = stack.pop()
        steps[u] = step
        for w in range(len(grid)):
            if grid[u][w] == 1 and levels[w] < levels[u]:
                stack.append(w)
        step += 1
    return steps

def maximum_income_alice_can_earn_bfs(grid, amount, bob_steps, n):
    source = 0
    earning = [-1]*n
    if bob_steps[0] == 0:
        earning[0] = amount[0]//2
    else:
        earning[0] = amount[0]
    queue = deque([source])
    step = 0
    while queue:
        size = len(queue)
        for x in range(size):
            u = queue.popleft()
            step += 1
            for w in range(n):
                if grid[u][w] != 0 and earning[w] == -1:
                    if bob_steps[w] == -1 or bob_steps[w] > step:
                        earning[w] = earning[u] + amount[w]
                    elif bob_steps[w] < step:
                        earning[w] = earning[u]
                    else:
                        earning[w] = earning[u] + amount[w]//2
                    queue.append(w)
    return earning

def find_leaf_nodes_from_adjacency_matrix(adj_matrix):
    n = len(adj_matrix)
    
    # Convert the adjacency matrix to an adjacency list
    adjacency_list = {i: [] for i in range(n)}
    for i in range(n):
        for j in range(n):
            if adj_matrix[i][j] == 1:
                adjacency_list[i].append(j)

    # Find all the leaf nodes
    leaf_nodes = [node for node in adjacency_list if len(adjacency_list[node]) == 1]
    
    return leaf_nodes

def main():
    n = len(amount)
    adj_grid = [[0]*n for i in range(n)]
    for x, y in edges:
        adj_grid[x][y] += 1
        adj_grid[y][x] += 1
    levels = update_levels(adj_grid, n)
    bob_steps = dfs_bob_steps(adj_grid, levels, bob)
    val = maximum_income_alice_can_earn_bfs(adj_grid, amount, bob_steps, n)
    # Leaf Nodes
    leaf_nodes = find_leaf_nodes_from_adjacency_matrix(adj_grid)
    for i in range(n):
        if sum(adj_grid[i]) == 0:
            leaf_nodes.append(i)
    print(leaf_nodes)
    max_val = val[leaf_nodes[0]]
    for i in leaf_nodes:
        max_val = max(max_val, val[i])
    print(max_val)
    return max_val

if __name__ == "__main__":
    main()