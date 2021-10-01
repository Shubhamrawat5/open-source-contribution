// Radix Sort in C++ Programming

#include <iostream>
using namespace std;

// Function to get the largest element from an array
int getMax(int arr[], int n)
{
  int max = arr[0];
  for (int i = 1; i < n; i++)
  {
    if (arr[i] > max)
    {
      max = arr[i];
    }
  }
  return max;
}

// Using counting sort to sort the elements in the basis of significant places
void countingSort(int arr[], int n, int place)
{
  const int max = 10;
  int output[n];
  int count[max];

  for (int i = 0; i < max; ++i)
  {
    count[i] = 0;
  }

  for (int i = 0; i < n; i++)
  {
    count[(arr[i] / place) % 10]++;
  }

  for (int i = 1; i < max; i++)
  {
    count[i] += count[i - 1];
  }

  for (int i = n - 1; i >= 0; i--)
  {
    output[count[(arr[i] / place) % 10] - 1] = arr[i];
    count[(arr[i] / place) % 10]--;
  }

  for (int i = 0; i < n; i++)
  {
    arr[i] = output[i];
  }
}

// Main function to implement radix sort
void radixSort(int arr[], int n)
{
  int max = getMax(arr, n);
  for (int place = 1; max / place > 0; place *= 10)
  {
    countingSort(arr, n, place);
  }
}

// Print an array
void print(int arr[], int n)
{
  for (int i = 0; i < n; i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;
}

// main program
int main()
{
  int arr[] = {121, 432, 564, 23, 1, 45, 788};
  int n = sizeof(arr) / sizeof(arr[0]);
  radixSort(arr, n);
  print(arr, n);
}