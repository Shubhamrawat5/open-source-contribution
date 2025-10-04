#include <stdio.h>
#include <stdlib.h>

struct Item {
    int value;
    int weight;
    double ratio;
};

int compareItems(const void *a, const void *b) {
    struct Item *itemA = (struct Item *)a;
    struct Item *itemB = (struct Item *)b;
    if (itemA->ratio < itemB->ratio) return 1;
    if (itemA->ratio > itemB->ratio) return -1;
    return 0;
}

double fractionalKnapsack(int W, struct Item arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i].ratio = (double)arr[i].value / arr[i].weight;
    }

    qsort(arr, n, sizeof(struct Item), compareItems);

    double totalValue = 0.0;
    for (int i = 0; i < n; i++) {
        if (W == 0) break;
        if (arr[i].weight <= W) {
            W -= arr[i].weight;
            totalValue += arr[i].value;
        } else {
            totalValue += arr[i].value * ((double)W / arr[i].weight);
            W = 0;
        }
    }
    return totalValue;
}

int main() {
    int W = 50;
    struct Item arr[] = {{60, 10}, {100, 20}, {120, 30}};
    int n = sizeof(arr) / sizeof(arr[0]);

    double maxValue = fractionalKnapsack(W, arr, n);
    printf("Maximum value in Knapsack = %.2f\n", maxValue);

    return 0;
}