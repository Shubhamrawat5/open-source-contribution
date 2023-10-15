#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

#define MAX_CITIES 10

struct City {
    double x, y;
};

int numCities;
struct City cities[MAX_CITIES];
int visited[MAX_CITIES];
double shortestDistance = INT_MAX;

double calculateDistance(struct City city1, struct City city2) {
    double dx = city1.x - city2.x;
    double dy = city1.y - city2.y;
    return sqrt(dx * dx + dy * dy);
}

void findShortestPath(int currentCity, int depth, double currentDistance) {
    if (depth == numCities) {
        currentDistance += calculateDistance(cities[currentCity], cities[0]);
        if (currentDistance < shortestDistance) {
            shortestDistance = currentDistance;
        }
        return;
    }

    for (int i = 0; i < numCities; i++) {
        if (!visited[i]) {
            visited[i] = 1;
            double newDistance = currentDistance + calculateDistance(cities[currentCity], cities[i]);
            findShortestPath(i, depth + 1, newDistance);
            visited[i] = 0;
        }
    }
}

int main() {
    printf("Enter the number of cities (up to %d): ", MAX_CITIES);
    scanf("%d", &numCities);

    if (numCities > MAX_CITIES || numCities < 1) {
        printf("Invalid number of cities. Please choose between 1 and %d.\n", MAX_CITIES);
        return 1;
    }

    printf("Enter the coordinates of each city (x y):\n");
    for (int i = 0; i < numCities; i++) {
        scanf("%lf %lf", &cities[i].x, &cities[i].y);
        visited[i] = 0;
    }

    findShortestPath(0, 1, 0.0);
    printf("The shortest distance to visit all cities and return to the starting city is: %lf\n", shortestDistance);

    return 0;
}
