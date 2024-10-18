import java.util.Arrays;

public class DijkstraAlgorithm {

    private static final int NO_PARENT = -1;


    private static int findMinDistance(int[] distance, Boolean[] visited, int verticesCount) {
        int min = Integer.MAX_VALUE;
        int minIndex = -1;

        for (int v = 0; v < verticesCount; v++) {
            if (!visited[v] && distance[v] < min) {
                min = distance[v];
                minIndex = v;
            }
        }
        return minIndex;
    }


    public static void dijkstra(int[][] graph, int source) {
        int verticesCount = graph.length;
        int[] distance = new int[verticesCount]; 
        Boolean[] visited = new Boolean[verticesCount]; 
        int[] parents = new int[verticesCount]; 

        Arrays.fill(distance, Integer.MAX_VALUE); 
        Arrays.fill(visited, false); 
        distance[source] = 0; 
        parents[source] = NO_PARENT; 


        for (int count = 0; count < verticesCount - 1; count++) {
            int u = findMinDistance(distance, visited, verticesCount);
            visited[u] = true;


            for (int v = 0; v < verticesCount; v++) {
                if (!visited[v] && graph[u][v] != 0 && distance[u] != Integer.MAX_VALUE &&
                        distance[u] + graph[u][v] < distance[v]) {
                    distance[v] = distance[u] + graph[u][v];
                    parents[v] = u;
                }
            }
        }

        printSolution(distance, parents, source);
    }


    private static void printPath(int currentVertex, int[] parents) {
        if (currentVertex == NO_PARENT) {
            return;
        }
        printPath(parents[currentVertex], parents);
        System.out.print(currentVertex + " ");
    }


    private static void printSolution(int[] distance, int[] parents, int source) {
        System.out.println("Vertex\t Distance\tPath");

        for (int vertexIndex = 0; vertexIndex < distance.length; vertexIndex++) {
            if (vertexIndex != source) {
                System.out.print("\n" + source + " -> ");
                System.out.print(vertexIndex + " \t\t ");
                System.out.print(distance[vertexIndex] + "\t\t");
                printPath(vertexIndex, parents);
            }
        }
    }

    public static void main(String[] args) {
        int[][] graph = new int[][]{
                {0, 4, 0, 0, 14},
                {4, 0, 5, 0, 10},
                {0, 5, 0, 2, 0},
                {0, 0, 2, 0, 10},
                {14, 10, 0, 10, 0}
        };

        dijkstra(graph, 0); 
    }
}
