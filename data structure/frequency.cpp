#include <iostream>
using namespace std;
int main()
{

    int arr[100]={1,1,1,2,2,4,5,7} , size=8 , arr2[100] , count=0 , item; 
    cout <<"given array is :";
    for (int  i = 0; i < size; i++){
        cout <<arr[i]<<" ";
    }
   
   cout <<"\nEnter item to be searched:";
   cin>>item;
   for (int  i = 0; i < size; i++)
   {
     if (item ==arr[i]){
        count+=1;
     }
   }

   cout << "occurance of "<< item <<" in an array is :"<< count;
   
    
    
    

return 0;
}
