#include <iostream>
#include <string.h>
#include <limits.h>
using namespace std;


       
  int knapSack(int W, int wt[], int val[], int n) 
{ 
  
    
    int i, j; 
    int dp[n + 1][W + 1]; 
  
   for(int i=0; i<=W; i++)
   {
       dp[0][i] = 0;
   }
   
   for(int i=0; i<=n; i++)
   {
       dp[i][0] = 0;
   }
    
    for (i = 1; i <= n; i++) {  
        for (j = 1; j <= W; j++) { 
           if (wt[i - 1] > j) 
                dp[i][j] = dp[i-1][j];
            else
                dp[i][j] = max(val[i - 1] + dp[i - 1][j - wt[i - 1]], dp[i - 1][j]);  
        } 
    } 
  
    return dp[n][W]; 
} 
    

int main() {
	
int val[] = { 10, 40, 30, 50 }; 
int wt[] = { 5, 4, 6, 3 }; 
int W = 10; 
int n = 4;
cout<<knapSack(W, wt, val, n);
	

}
