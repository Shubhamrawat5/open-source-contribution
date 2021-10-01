//Uses simple linear search to search for min and max element.

#include<iostream>
using namespace std;
void maxelement(int array[], int size) //takes two elements array, and size of the Array
{
  int i,max;
  max=array[0];
  for(i=0;i<size;i++)
  {
    if(array[i]>max)
     {
       max=array[i];
     }
     else continue;
  }
  cout<<"The maximum element found in the Array is "<<max<<"\n";
}
void minelement(int array[], int size) //takes two elements array, and size of the Array
{
  int i,min;
  min=array[0];
  for(i=0;i<size;i++)
  {
    if(array[i]<min)
     {
       min=array[i];
     }
     else continue;
  }
  cout<<"The minimum Element found in the Array is "<<min<<"\n";
}
int main()
{
  int size;
  cout<<"enter size of the array \n";
  cin>>size;
  int array[size];
  if(size==0)
  cout<<"Array is Empty!";
  else
  {
    cout<<"Enter elements into the Array"<<"\n";
    int i=0;
    for(i=0;i<size;i++)
     {
       cin>>array[i];
     }
     maxelement(array, size);
     minelement(array, size);
  }
  return 0;
}
