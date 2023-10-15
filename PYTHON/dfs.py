def dfs(graph, start):
    visited = set()

    def visit(node):
        if node not in visited:
            visited.add(node)
            print(node, end=' ')

            for neighbor in graph[node]:
                visit(neighbor)

graph = {}
num_nodes = int(input("Enter the number of nodes: "))

for _ in range(num_nodes):
    node = input("Enter a node: ")
    neighbors = input("Enter neighbors of the node (comma-separated): ").split(',')
    graph[node] = [neighbor.strip() for neighbor in neighbors]

start_node = input("Enter the starting node: ")

print("DFS Result:")
dfs(graph, start_node)
