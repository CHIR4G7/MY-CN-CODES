from collections import defaultdict
def minimumTreePath(n, edges, visitNodes):
    parent = defaultdict(lambda:-1)
    G = defaultdict(list)
    for v,w in edges:
        G[v].append(w)
        G[w].append(v)
    visited = set()
    def dfs(v, u):
        if v in visited: return
        parent[v] = u
        visited.add(v)
        for w in G[v]:
            if w == u: continue
            dfs(w, v)
    dfs(1,-1)
    cores = set()
    v = n
    res = -1
    while v != -1:
        cores.add(v)
        res += 1
        v = parent[v]
    for v in visitNodes:
        tmpres = 0
        while v not in cores:
            cores.add(v)
            tmpres += 2
            v = parent[v]
        res += tmpres
    return res