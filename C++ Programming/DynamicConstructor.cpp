#include<iostream>
#include<iomanip>
using namespace std;
class BankDeposit{
    int principal;
    int year;
    float interestRate;
    float returnValue;
    
    public :
    BankDeposit(){}
    BankDeposit(int p,int y,float r);
    BankDeposit(int p,int y,int r);
    void show(void);
};

BankDeposit::BankDeposit(int p,int y,float r)
{
    principal=p;
    year = y;
    interestRate = r;
    returnValue = principal;
    for(int i=0;i<y;i++)
    {
        returnValue = returnValue * (1+interestRate); 
    }
}

BankDeposit::BankDeposit(int p,int y,int r)
{
    principal=p;
    year = y;
    interestRate =  float(r)/100;
    returnValue = principal;
    for(int i=0;i<y;i++)
    {
        returnValue = returnValue * (1+interestRate); 
    }
}
void BankDeposit:: show()
{
    cout<<endl<<"Your Principal amount : "<<principal<<endl<<"Return value : "<<returnValue<<endl;
}
int main()
{
    BankDeposit x,y,z;
    int p1,y1;
    float R1;
    int r1;
    cout<<"Enter the values for p,y,R : ";
    x = BankDeposit();
    cin>>p1>>y1>>R1;
    y = BankDeposit(p1,y1,R1);
    y.show();
    cout<<endl<<"Enter the values for p,y,r : ";
    cin>>p1>>y1>>r1;
    z = BankDeposit(p1,y1,r1);
    z.show();
}
