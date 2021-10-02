// Linear Search in C

#include <stdio.h>

int search(int array[], int n, int x) {
  
  // Going through array sequencially
  for (int i = 0; i < n; i++)
    if (array[i] == x)
      return i;
  return -1;
}

int main() {
  int array[] = {12, 54, 10, 21, 19,5,2};
  int x,i;
  printf("Given the array\n");
  int n = sizeof(array) / sizeof(array[0]);
  for(i=0;i<n;i++)
  {
      printf("\t%d",array[i]);
  }
  printf("\nEnter number to be searched:");
  scanf("%d",&x);
  
  int result = search(array, n, x);

  (result == -1) ? printf("Data not found") : printf("Data found at index: %d", result);
}
