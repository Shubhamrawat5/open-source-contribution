#include <iostream>
using namespace std;

int bs (int arr[] , int d , int n){
    int low=0 , mid;
    int high=(n-1);
    while (low <=high)
    {
        mid=(low+high)/2;
        if (arr[mid]==d)
           {
            return mid;
            
           }
        else if (d>arr[mid]){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }

    return -1;

    
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
    int res=bs(arr , item , size);
    if (res==-1){
        cout<<"element is not present in given array"<<endl;
    }
    else {
        cout<<"Element is found at "<<res<<" index";
    }
    
return 0;
}
