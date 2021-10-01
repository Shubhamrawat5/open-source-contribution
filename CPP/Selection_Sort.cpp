#include <bits/stdc++.h>
using namespace std;

void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

void selectionSort(int a[], int n)
{
	int i, j, min;

	
	for (i = 0; i < n-1; i++)
	{
		
		min = i;
		for (j = i+1; j < n; j++)
		if (a[j] < a[min])
			min = j;

		
		swap(&a[min], &a[i]);
	}
}


void printArray(int a[], int size)
{
	int i;
	for (i=0; i < size; i++)
		cout << a[i] << " ";
	cout << endl;
}


int main()
{
	int a[] = {32, 39, 7, 41, 18, 23};
	int n = sizeof(a)/sizeof(a[0]);
	selectionSort(a, n);
	cout << "Sorted array: \n";
	printArray(a, n);
	return 0;
}
