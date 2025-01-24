from typing import List
class Solution:
    def is_safe_node(self, graph: List[List[int]], source: int, Terminal_nodes: set[int], visited: List[bool]) -> bool:
        if len(set(graph[source]).union(Terminal_nodes)) == len(graph[source]):
            return True
        else:
            result = True
            for i in graph[i]:
                if visited[i] == False:
                    visited[i] = True
                    result = result | self.is_safe_node(graph, i, Terminal_nodes)
                    visited[i] = False
            return result
        
    
    def eventualSafeNodes(self, graph: List[List[int]]) -> List[int]:
        pass