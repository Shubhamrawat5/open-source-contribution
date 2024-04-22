#include <iostream>
using namespace std;
int main()
{
    int arr[]={1,2,3,3,5,6,7,8};
    int n=8;
    int item , n_item;

    cout<<"Orginal array:"<<endl;
    for (int  i = 0; i < n; i++)

    {
       cout<<arr[i]<<" ";    /* code */
    }
    
    cout <<"\nEnter position to be replaced:";
    cin>>item;
    cout<<"Enter new element:";
    cin>>n_item;
    for (int  i = 0; i < n; i++)
    {
        if (i==item){
           arr[i]=n_item;
           break;
           
        }
    }


    cout<<"\nArray after update:"<<endl;
    for (int  i = 0; i < n; i++)

    {
       cout<<arr[i]<<" ";    /* code */
    }
    
return 0;
}
