class BiGraph():
    def __init__(self, V):
        self.V = V
        self.graph = [[0 for column in range(V)] for row in range(V)]
    
    def isBi(self, src):
        colArr = [-1]*self.V
        colArr[src] = 1

        queue = []
        queue.append(src)

        while queue:
            u = queue.pop()

            if self.graph[u][u] == 1:
                return False
            
            for v in range(self.V):
                if self.graph[u][v] == 1 and colArr[v] == -1:
                    colArr[v] = 1 - colArr[u]
                    queue.append(v)
                elif self.graph[u][v] == 1 and colArr[v] == colArr[u]:
                    return False
            
        return True