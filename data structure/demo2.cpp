#include<iostream>
using namespace std;
int main(){
    int a[10]={1,2,3,4,5,6,7,8,9,12};
    int i,num,replace;
    cout<<"replacing a number";
    cout<<"array is";
    for(i=0;i<10;i++)
    {
        cout<<"a["<<i<<"]="<<a[i]<<endl;
    }
    cout<<"enter a position in which you want to replace";
    cin>>num;
    cout<<"enter the number you want to print ";
    cin>>replace;
    for(i=0;i<10;i++)
    {
        if(i==num)
        {
            a[i]=replace;
        }
    }
    for(i=0;i<10;i++)
    {
        cout<<"a["<<i<<"]="<<a[i]<<endl;
    }
return 0;
}