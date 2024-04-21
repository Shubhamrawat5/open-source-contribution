#include <iostream>
using namespace std;

int visited[4]={0,0,0,0};
int a[4][4]={
 {0,1,0,1},
 {1,0,0,0},
 {0,1,0,0},
 {0,0,1,0}


};

void dfs(int i){
    visited[i]=1;
    cout<<i<<" ";
    for (int  j = 0; j < 4; j++)
    {
        if (a[i][j]==1 && visited[j]==0){
            dfs(j);
        }
    }
    
}
int main()
{
    dfs(1);
return 0;
}
