#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int tsp(vector<vector<int>>& graph, int start) {
    vector<int> cities;
    for (int i = 0; i < graph.size(); i++) {
        if (i != start) {
            cities.push_back(i);
        }
    }

    int minTourCost = INT_MAX;
    do {
        int tourCost = 0;
        int curCity = start;

        for (int i = 0; i < cities.size(); i++) {
            tourCost += graph[curCity][cities[i]];
            curCity = cities[i];
        }

        tourCost += graph[curCity][start];
        minTourCost = min(minTourCost, tourCost);

    } while (next_permutation(cities.begin(), cities.end()));

    return minTourCost;
}

int main() {
    int n;
    cout << "Enter the number of cities: ";
    cin >> n;

    vector<vector<int>> graph(n, vector<int>(n));

    cout << "Enter the adjacency matrix for the cities:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }

    int start;
    cout << "Enter the starting city: ";
    cin >> start;

    int minCost = tsp(graph, start);

    cout << "Minimum tour cost: " << minCost << endl;

    return 0;
}
