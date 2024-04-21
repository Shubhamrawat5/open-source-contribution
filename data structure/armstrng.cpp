#include <iostream>
using namespace std;
int main()
{

    int num, rem  , temp , sum=0;
    cout<<"Enter a number:";
    cin>> num;
    temp=num;
    while (num>0){

         rem=num%10;
         sum+=rem*rem*rem;
         num/=10;

  
    }

    if (temp==sum){
        cout<<"Number is Armstrong number";
    }
    else{
        cout<<"Number is not a Armstrong number";
    }
    
return 0;
}
