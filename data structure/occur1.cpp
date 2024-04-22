#include <iostream>
using namespace std;
int main()
{  
    int arr[100] , visited[100] , size , count ;
    cout <<"Enter size of an array:";
    cin>> size;
    for (int  i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    for (int  i = 0; i < size; i++)
    {
       count=1;
       if (visited[i]==1){
            continue;
       }
        else{
                for (int  j = i+1; j < size; j++)
                {
                    if (arr[i]==arr[j])
                    {
                        count++;
                        visited[j]=1;
                    }
                }

                cout <<"Occurance of "<< arr[i]<< "is "<< count<<endl;
                
        }

    }
    
    
return 0;
}
