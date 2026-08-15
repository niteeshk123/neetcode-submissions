class Solution:
    def foreignDictionary(self, words: List[str]) -> str:
        nodes = []
        for word in words:
            for c in word:
                if c not in nodes:
                    nodes.append(c)
        
        adj = {c: [] for c in nodes}
        print(adj)

        # create graph
        for i in range(len(words)-1):
            w1 = words[i]
            w2 = words[i+1]

            minLen = min(len(w1), len(w2))
            if len(w1)>len(w2) and w1[:minLen]==w2[:minLen]:
                return ""
                # continue
            j = 0
            for j in range(minLen):
                if w2[j]!=w1[j]:
                    if w2[j] not in adj[w1[j]]:
                        adj[w1[j]].append(w2[j])
                        print("---", w1, w2, j)
                    break
        print(adj)
        incoming={c:0 for c in nodes}
        for node in nodes:
            for nei in adj[node]:
                incoming[nei]+=1
        
        print(adj)
        print("incoming ", incoming)
        queue = []
        for node in nodes:
            if incoming[node] == 0:
                queue.append(node)
        
        res = []
        while(len(queue)>0):
            u = queue[0]
            queue.pop(0)
            res.append(u)
            for nei in adj[u]:
                incoming[nei]-=1
                if incoming[nei] == 0:
                    queue.append(nei)
            print("new inc", incoming)
        
        print(res , nodes)
        if len(res) != len(nodes):
            return ""
        
        s = ""
        for c in res:
            s=s+c
        return s

