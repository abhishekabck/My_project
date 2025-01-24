def is_connected_DFS(graph, source, dest) -> bool:
        if source == dest:
            return True
        stack = [source]
        visited = [False]*len(graph)

        while stack:
            v = stack.pop()
            if not visited[v]:
                visited[v] = True
                for i in range(len(graph[v])):
                    if graph[v][i] == dest:
                        return True
                    if not visited[graph[v][i]]:
                        stack.append(graph[v][i])
        return False
    

graph = [
    [1, 3, 6],
    [2, 4],
    [5],
    [1, 4],
    [5],
    [],
    [5]
]


source = 1
dest = 6
print(is_connected_DFS(graph, source, dest))