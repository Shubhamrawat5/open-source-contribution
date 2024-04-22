#include <iostream>
using namespace std;
int main()
{
   int   arr[4] , size , idx;
   cout <<"Enter size:";
   cin>> size;
    cout <<"enter element in an array :";
    for (int  i = 0; i < size; i++){
        cin >> arr[i];
    }
    cout <<"given array is :";
    for (int  i = 0; i < size; i++){
        cout <<arr[i]<<" ";
    }

    cout <<"\nenter index  of element  you want to delete";
    cin>>idx;
    if (idx > size-1){
        cout<<"index out of range...\n";
        cout<<"no updatation is done\n";

    }
    else{
    for (int  i = idx; i < size-1; i++){
        arr[i]=arr[i+1];
        
        
    }
    size=size-1;
    cout<<"updated array is :"<<endl;
     for (int  i = 0; i < size; i++){
        cout <<arr[i]<<" ";
    }
    }
 

    
return 0;
}
