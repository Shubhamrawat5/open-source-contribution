// C program for insertion sort
#include <math.h>
#include <stdio.h>

/* Function to sort an array using insertion sort*/
void insertionSort(int arr[], int n)
{
	int i, key, j;
	for (i = 1; i < n; i++) {
		key = arr[i];
		j = i - 1;

		/* Move elements of arr[0..i-1], that are
		greater than key, to one position ahead
		of their current position */
		while (j >= 0 && arr[j] > key) {
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
}

// A utility function to print an array of size n
void printArray(int arr[], int n)
{
	int i;
	for (i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

/* Driver program to test insertion sort */
int main()
{
	int arr[] = {2, 16, 20, 14, 9, 96, 87};
	int i;
	printf("Before Sorted Array is\n");
	int n = sizeof(arr) / sizeof(arr[0]);
    for(i=0;i<n;i++){
        printf("\t%d",arr[i]);
    }
	insertionSort(arr, n);
	printf("\nThe sorted array is\n");
	printArray(arr, n);

	return 0;
}