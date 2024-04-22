#include <iostream>
using namespace std;

int linear_search(int arr[] , int  item , int size){
     int found=0;
     for (int  i = 0; i < size ; i++)
     {
       if (item ==arr[i])
       {
        found=1;
        break;
       }

       
     }
    return found;
     



}
int main()
{
    int arr[100]  , size , item;
    cout<<"Enter size of an array:";
    cin >> size;
    cout<<"Enter elements:"<<endl;
    for (int  i = 0; i <size ; i++)
    {
        cin >> arr[i];
    }
     for (int  i = 0; i <size ; i++)
    {
        cout << "Element at ["<<i<<"]="<<arr[i]<<endl;
    }
    cout<<"Enter item to be searched:";
    cin >> item;
    int res=linear_search(arr , item ,  size)  ;
    if (res==1){
        cout <<"item is found "<<endl;

    }  
    else{
        cout <<"item is not found"<<endl;
    }
    
    
return 0;
}
