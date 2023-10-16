#include <stdio.h>
#include <stdbool.h>

#define MAX_NODES 100

bool visited[MAX_NODES];
int graph[MAX_NODES][MAX_NODES];
int numNodes;

void initialize() {
    for (int i = 0; i < MAX_NODES; i++) {
        visited[i] = false;
        for (int j = 0; j < MAX_NODES; j++) {
            graph[i][j] = 0;
        }
    }
    numNodes = 0;
}

void addEdge(int u, int v) {
    graph[u][v] = 1;
    graph[v][u] = 1;
}

void dfs(int node) {
    visited[node] = true;
    printf("Visited node: %d\n", node);

    for (int i = 0; i < numNodes; i++) {
        if (graph[node][i] == 1 && !visited[i]) {
            dfs(i);
        }
    }
}

int main() {
    initialize();
    
    int numEdges, u, v;
    printf("Enter the number of nodes: ");
    scanf("%d", &numNodes);
    printf("Enter the number of edges: ");
    scanf("%d", &numEdges);
    
    printf("Enter the edges (u v):\n");
    for (int i = 0; i < numEdges; i++) {
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }

    printf("Enter the starting node for DFS: ");
    int startNode;
    scanf("%d", &startNode);

    printf("Depth-First Traversal starting from node %d:\n", startNode);
    dfs(startNode);

    return 0;
}
