#include<bits/stdc++.h>
using namespace std;

void TrappingRainWater(int arr[], int n){   // Function

int result = 0;

    for (int i = 1; i < n-1; i++)
    {
        // Right
        int right = arr[i];
        for (int j = i+1; j < n ; j++)
        {
            right = max(right,arr[j]);
        }
        
        // Left

        int left = arr[i];
        for (int j = 0; j < i ; j++)
        {
            left = max(left,arr[j]);
        }
        
        result = result + (min(left,right) - arr[i]); // Calculating Result
    }
    
    cout<< result ;
}

int main()
{   int arr[] = {0,1,0,2,1,0,1,3,2,1,2,1};

    int n = sizeof(arr)/sizeof(arr[0]);

    TrappingRainWater(arr,n);  // Function Call  
    return 0;
}
