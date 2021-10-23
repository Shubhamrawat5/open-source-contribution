#include<iostream>
#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
 
// Function to get maximum length of string in array a[].
int getmax(string a[], int n)
{
  int max = a[0].length();
  for (int x=1; x<n; x++)
    if (a[x].length() > max)
      max = a[x].length();
  return max;
}

int sTi(char str)
{
    int temp = 0;
    for (int i = 0; i < 1; i++) {
  
        // Since ASCII value of character from '0' to '9' are contiguous. So if we subtract '0' from ASCII value of a digit, we get v
        temp=(str - '0');
    }
    return temp;
}

// Function to do counting sort according to significant digits repesented by
// last character of string comverted to int using sTi function
void CountSort(string a[], int n, int exp)
{  
  int i, count[10] = {0};
  string result[n];
 
  // Counting occurence of digits
  for (i =0; i <n; i++){
  count[sTi((a[i][a[i].length()-exp]))]++;
  // cout<<sTi((a[i][a[i].length()-exp]))<<endl;
  }
 
  // Changing the position of count so that it appears at actual position in result.
  for (i =1; i<10; ++i)
    count[i] += count[i-1];
 
  // Resultant output array
  for (i =n-1; i>= 0; i--)
  {
    result[count[sTi(a[i][a[i].length()-exp])] - 1] = a[i];
    count[sTi(a[i][a[i].length()-exp])]--;
  }
  for (i =0; i <n; i++)
    a[i] = result[i];
}
 
// Radix Sort to sort a[] of given size.
void radixsort(string a[], int n)
{
  int exp, i;
  i = getmax(a, n);
  for (exp = 1; exp < i; exp++)
    CountSort(a, n, exp);
  cout<<"sorted list"<<endl;
  for (int i = 0; i < n; i++){
    cout<<a[i]<<" ";
  }
}
// Driver Program
int main()
{
  int n;
  cout<<" Enter the number of elements to be sorted: ";
  cin>>n;
  string a[n];
  
  cout<<"\n Enter the elements: ";
  for(int i =0; i <n; i++)
  {
    cin>>a[i];
  }
   
  radixsort(a, n);
 
  // Printing the sorted list.

  return 0;
}