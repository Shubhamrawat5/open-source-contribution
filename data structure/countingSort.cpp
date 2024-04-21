#include <iostream>
int fabo(int n){
    if (n==1 ){
        return 0;
    }
    else if (n==2){
        return 1;

    }
    else {
        return fabo(n-1)+fabo(n-2);
    }
}
using namespace std;
int main()
{
    int num=10;

    for (int i = 1; i <=num; i++)
    {
        cout<<fabo(i)<<endl;
        
        
    }
    
    
return 0;
}
