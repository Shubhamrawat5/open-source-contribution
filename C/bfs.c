#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

int graph[MAX_VERTICES][MAX_VERTICES];
int visited[MAX_VERTICES];
int queue[MAX_VERTICES];
int front = -1, rear = -1;

void enqueue(int value) {
    if (rear == MAX_VERTICES - 1) {
        printf("Queue is full\n");
        return;
    }
    if (front == -1)
        front = 0;
    rear++;
    queue[rear] = value;
}

int dequeue() {
    if (front == -1) {
        printf("Queue is empty\n");
        return -1;
    }
    int item = queue[front];
    front++;
    if (front > rear)
        front = rear = -1;
    return item;
}

void bfs(int vertices, int start) {
    for (int i = 0; i < vertices; i++)
        visited[i] = 0;

    visited[start] = 1;
    printf("Breadth First Search starting from vertex %d: ", start);
    printf("%d ", start);

    enqueue(start);

    while (front != -1) {
        int currentVertex = dequeue();

        for (int i = 0; i < vertices; i++) {
            if (graph[currentVertex][i] == 1 && !visited[i]) {
                printf("%d ", i);
                visited[i] = 1;
                enqueue(i);
            }
        }
    }
    printf("\n");
}

int main() {
    int vertices;
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    int startVertex;
    printf("Enter the starting vertex: ");
    scanf("%d", &startVertex);

    bfs(vertices, startVertex);

    return 0;
}
