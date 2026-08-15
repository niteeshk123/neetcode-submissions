class Solution:
    def validTree(self, n: int, edges: List[List[int]]) -> bool:
        visited = [0 for i in range(n)]
        adj = [[] for i in range(n)]
        for u,v in edges:
            adj[u].append(v)
            adj[v].append(u)

        def dfs(node, par):
            nonlocal visited

            for v in adj[node]:
                if v == par:
                    continue
                if visited[v]==0:
                    visited[v] = 1
                    if not dfs(v, node):
                        return False
                else:
                    return False
            return True 
        
        visited[0] = True
        if not dfs(0, -1):
            return False
        for i in range(n):
            if visited[i]==0:
                return False
        return True
