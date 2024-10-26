#include<iostream>
#include<iomanip>
using namespace std;
class Dmart
{
    private :
    int productid[10];
    int productprice[10];
    int count;
    public :
    void setproduct(void);
    void displaydetails(void);
    void setcount(void)
    {
        count=1;
    }
};
void Dmart::setproduct(void)
{
   cout<<"Enter you product ID : ";
   cin>>productid[count];
   cout<<"Enter the price of product : "; 
   cin>>productprice[count];
   count++;
}
void Dmart::displaydetails(void)
{
    for(int i=1;i<count;i++)
    cout<<"ProductID : "<<productid[i]<<" Price : "<<productprice[i]<<endl;
}
int main()
{
    
    Dmart P;
    P.setcount();
    for(int i=0;i<3;i++)
    {
        P.setproduct();
    }
    P.displaydetails();
}
