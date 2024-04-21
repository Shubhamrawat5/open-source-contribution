#include <iostream>
using namespace std;
int main()
{

    int arr[100] , size , count;
    cin >> size ;
    int checked=1;
   
    int visited[100];
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
        for (int  j = i+1; j < size;j++)
        {
            if (arr[i]==arr[j])
            {
                count++;
                visited[j]=1;
            }
            
        }
         cout << arr[i]<<"-----"<< count<<endl;
       }
        
    }
    
    
 
    

    
    
    
   
   
    
    
    

return 0;
}
