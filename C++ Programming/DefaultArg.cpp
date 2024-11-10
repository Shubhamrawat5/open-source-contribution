#include<iostream>
#include<iomanip>
using namespace std;
float moneyRecived(int currentMoney ,float intperc=1.04)//this 1.04 is default arg
{
    return currentMoney*intperc;
}

int main()
{
    int money =100;
    cout<<"If u have"<< money<<"RS in your bank acc,You will receive "<<moneyRecived(money)<<"Rs after 1year";
    cout<<endl<<"For VIP: If u have "<<money<<"RS in your bank acc, you will recive "<<moneyRecived(money,2.1)<<"Rs after 1year";//this 2.1 is the derived arg 
    return 0;
}