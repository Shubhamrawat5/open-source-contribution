#include<iostream>
#include<math.h>
using namespace std;

int max(int n, int m, int l){
    if(n>m){
        if(n>l){
            cout<<n<<" is max"<<endl;
        }
        else{
            cout<<l<<" is max"<<endl;
        }
    }
    else{
        if(m>l){
            cout<<m<<" is max"<<endl;
        }
        else{
            cout<<l<<" is max"<<endl;
        }
    }
    return 0;

}
int min(int n, int m, int l){
    if(n>m){
        if(l>m){
            cout<<m<<" is min";
        }
        else{
            cout<<l<<" is min";
        }
    }
    else{
        if(l>n){
            cout<<n<<" is min";
        }
        else{
            cout<<l<<" is min";
        }
    }
    return 0;
}

int main()
{
    int x,y,z;
    cin>>x>>y>>z;

    max(x,y,z);
    min(x,y,z);

    return 0;
}

