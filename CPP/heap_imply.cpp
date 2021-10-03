#include <iostream>
using namespace std;
#define SIZE 100;
void reup(int arr[], int i)
{
    int k = arr[i];
    int par = i / 2;
    while (arr[par] < k) //restores up the larger element
    {
        arr[i] = arr[par];
        i = par;
        par = i / 2;
    }
    arr[i] = k;
}
void add(int n, int arr[], int *hsize)
{
    (*hsize)++; //Increase the heap size when the element is inserted
    arr[*hsize] = n;
    reup(arr, *hsize);
}
void redown(int arr[], int i, int hsize) //puts the smallest element in the bottom of the heap
{
    int lchild = 2 * i, rchild = lchild + 1; //left child and right child of a node in the heap
    int n = arr[i];
    while (rchild <= hsize) //loop condition checking for shifting of elements
    {
        if (n >= arr[lchild] && n >= arr[rchild])
        {
            arr[i] = n;
            return;
        }
        else if (arr[lchild] > arr[rchild])
        {
            arr[i] = arr[lchild];
            i = lchild;
        }
        else
        {
            arr[i] = arr[rchild];
            i = rchild;
        }
        lchild = 2 * i;
        rchild = lchild + 1;
    }
    if (lchild == hsize && n < arr[lchild]) //for the last element to be placed
    {
        arr[i] = arr[lchild];
        i = lchild;
    }
    arr[i] = n;
}
int del(int arr[], int *hsize)
{
    int max = arr[1];     //root element
    arr[1] = arr[*hsize]; //replace with the last element of the heap
    (*hsize)--;           //whenever an element is deleted, size of the heap decreases
    redown(arr, 1, *hsize);
    return max;
}
void disp(int arr[], int hsize)
{
    int i;
    if (hsize == 0) //Empty Heap condition
    {
        cout << "Empty Heap" << endl;
        return;
    }
    for (i = 1; i <= hsize; i++)
        cout << arr[i] << endl; //Displaying the Heap
}
void build(int arr[], int size) //Building the Heap from scratch when no element is present initially
{
    int i;
    for (i = 2; i <= size; i++)
        reup(arr, i);
}
//Main Function -
int main()
{
    int arr[100]; //Heap Array
    int hsize = 0;
    int i, ch, n;
    arr[0] = SIZE;
    while (1)
    { //Menu Options -
        cout << "1. Insert Element" << endl;
        cout << "2. Delete Element" << endl;
        cout << "3. Display Heap" << endl;
        cout << "4. Build the Heap" << endl;
        cout << "Enter your Choice: " << endl;
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "Enter element to be inserted" << endl; //add elements to the heap
            cin >> n;
            add(n, arr, &hsize);
            break;
        case 2:
            if (hsize == 0)
                cout << "Empty Heap" << endl;
            else
            {
                n = del(arr, &hsize); //delete elements from the heap
            }
            break;
        case 3:
            disp(arr, hsize); //display the heap
            break;
        case 4:
            cout << "Size of the Array: " << endl;
            cin >> hsize;
            cout << "Enter the elements to be inserted in the Array: " << endl;
            for (i = 1; i <= hsize; i++) //building the heap from scratch
                cin >> arr[i];
            build(arr, hsize);
            break;
        }
    }
}