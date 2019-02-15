''' Calculating subtree size using Stack '''

MAX = 100010

subSize = [0 for i in range(MAX)]
subMin  = [0 for i in range(MAX)]
graph   = [[] for i in range(MAX)]

def dfs(source, n):
	vis = [0  for i in range(n + 1)]
	par = [0 for i in range(n + 1)]
	subSize[source] = 1
	vis[source] = 1

	stack1 = [source]
	stack2 = []
	par[source] = -1

	while len(stack1) > 0:
		source = stack1.pop()
		vis[source] = 1
		stack2.append(source)
		for x in graph[source]:
			if(x != 0 and vis[x] == 0):
				par[x] = source
				stack1.append(x)
	
	while(len(stack2) > 0):
		source = stack2.pop()
		subSize[source] = 1
		subMin[source] = source
		for x in graph[source]:
			if(x != 0 and x != par[source]):
				subSize[source] += subSize[x]
				subMin[source] = min(subMin[source], subMin[x])


n = int(input())
for _ in range(n - 1):
	x, y = map(int, input().strip().split())
	graph[x].append(y)
	graph[y].append(x)


dfs(1, n)
for i in range(n + 1):
	print(i, subSize[i], subMin[i])
