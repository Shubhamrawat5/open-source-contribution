
# Articulation Point : It is a point/vertex in an undirected graph, which if removed along with it's edges would cause the entire graph to
# split in two different graphs.




from collections import defaultdict


class Graph:
    # Initializer
	def __init__(self, vertices):
		self.V = vertices
		self.stack = defaultdict(list) 
		self.Time = 0

	# function to add an edge to graph
	def edgeAdd(self, u, v):
		self.stack[u].append(v)
		self.stack[v].append(u)

    
	def articulationPointRev(self, u, visited, ap, parent, low, disc):
		children = 0
		visited[u]= True
		disc[u] = self.Time
		low[u] = self.Time
		self.Time += 1

		for v in self.stack[u]:
			if visited[v] == False :
				parent[v] = u
				children += 1
				self.articulationPointRev(v, visited, ap, parent, low, disc)
				low[u] = min(low[u], low[v])
				if parent[u] == -1 and children > 1:
					ap[u] = True
				if parent[u] != -1 and low[v] >= disc[u]:
					ap[u] = True

			elif v != parent[u]:
				low[u] = min(low[u], disc[v])

	def articulationPoint(self):
		visited = [False] * (self.V)
		disc = [float("Inf")] * (self.V)
		low = [float("Inf")] * (self.V)
		parent = [-1] * (self.V)
		ap = [False] * (self.V)

		for i in range(self.V):
			if visited[i] == False:
				self.articulationPointRev(i, visited, ap, parent, low, disc)

		for index, value in enumerate (ap):
			if value == True: print(index)



 # You may use any graph instead of this one.
g1 = Graph(5) 
g1.edgeAdd(1, 0) 
g1.edgeAdd(0, 2) 
g1.edgeAdd(2, 1) 
g1.edgeAdd(0, 3) 
g1.edgeAdd(3, 4) 
   
print("Articulation points {Undirected Graph}: ")
g1.articulationPoint() 
  
