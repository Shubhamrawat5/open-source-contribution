def buildGraph(edges):
	graph = {}
	for edge in edges:
		a,b = edge
		if a not in graph: graph[a] = []
		if b not in graph: graph[b] = []
		graph[a] += [b]
		graph[b] += [a]
	return graph


def shortestPath(edges, nodeA, nodeB):
	graph = buildGraph(edges)
	visited = set()
	visited.add(nodeA)
	queue = [[nodeA,0]]
	while len(queue) > 0:
		# print(queue)
		node, dist = queue.pop(0)
		if node == nodeB:
			return dist
		for neighbor in graph[node]:
			if (visited.__contains__(neighbor)) == False:
				visited.add(neighbor)
				queue.append([neighbor, dist+1])
				print(queue)
	return -1



edges = [
	['a','b'],
	['b','c'],
	['a','d'],
	['d','e'],
	['c','e'],
]

print(shortestPath(edges,'a','c'))