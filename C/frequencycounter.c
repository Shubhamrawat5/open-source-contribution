#include <stdio.h>

void trackFrequency(int arr[], int n) {
    int frequency[1000] = {0};

    for (int i = 0; i < n; i++) {
        frequency[arr[i]]++;
    }

    printf("Frequency of integers in the array:\n");
    for (int i = 0; i < 1000; i++) {
        if (frequency[i] > 0) {
            printf("%d occurs %d times\n", i, frequency[i]);
        }
    }
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[1000];
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    trackFrequency(arr, n);

    return 0;
}
