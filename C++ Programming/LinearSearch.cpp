#include<iostream>
using namespace std;
void LinearSearch(int  array[],int size ,int key)
{
    int z=0;
    for(int i=0;i<size;i++)
    {       
        if(array[i]==key)
        {
            cout<<"Found : "<<i<<endl;
            z=1;
        }
    }
        if (z==0)
        {
            cout<<"Element not found"<<endl;
        }
    
}
int main()
{
    int size;
    cout<<"Enter the size of array : "<<endl;
    cin>>size;
    int array[size];
    cout<<"Enter the elements in array : "<<endl;
    for(int i=0;i<size;i++)
    {
        cin>>array[i];
    }
    int key;
    cout<<"Enter the element to be found : "<<endl;
    cin>>key;
    LinearSearch(array,size,key);
}