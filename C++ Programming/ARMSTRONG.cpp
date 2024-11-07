#include<iostream>
using namespace std ;

int  main(){

int num ;
cout<<"Enter your number : ";
cin>>num;
int t=num;
int sum= 0 ;
int dig;
while(num>0){

dig=num%10;
sum=sum+(dig*dig*dig);
num=num/10;


}

//cout<<sum<<endl;


if(sum==t){
    cout<<"The entered number is Armstrong number "<<endl;
}
else
    cout<<"The entered number is not  a Armstrong number "<<endl;

    return 0 ; 
}