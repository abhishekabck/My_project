from typing import List

class Solution:
    def eventualSafeNodes(self, graph: List[List[int]]) -> List[int]:
        n = len(graph)
        color = [0] * n
        
        def dfs(node):
            if color[node] > 0:
                return color[node] == 2
            color[node] = 1
            for neighbor in graph[node]:
                if color[neighbor] == 2:
                    continue
                if color[neighbor] == 1 or not dfs(neighbor):
                    return False
            color[node] = 2
            return True
        
        result = []
        for i in range(n):
            if dfs(i):
                result.append(i)
                
        return result
    
safe_nodes = Solution().eventualSafeNodes(graph=[[1,2],[2,3],[5],[0],[5],[],[]])
print(safe_nodes)
