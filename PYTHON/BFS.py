from collections import deque

def bfs(graph, start):
    visited = set()
    queue = deque([start])
    result = []

    while queue:
        node = queue.popleft()
        if node not in visited:
            visited.add(node)
            result.append(node)

            for neighbor in graph[node]:
                if neighbor not in visited:
                    queue.append(neighbor)

    return result

# User input for the graph
graph = {}
num_nodes = int(input("Enter the number of nodes: "))

for i in range(num_nodes):
    node = input(f"Enter the node {i + 1}: ").strip()
    neighbors = input(f"Enter neighbors of {node} (comma-separated): ").split(',')
    graph[node] = [neighbor.strip() for neighbor in neighbors]

start_node = input("Enter the starting node: ")

# Perform BFS and print the result
bfs_result = bfs(graph, start_node)
print("BFS Result:", ' -> '.join(bfs_result))
