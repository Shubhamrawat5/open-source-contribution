#include<iostream>
#include<iomanip>
using namespace std;
int count = 0;
class Num
{
    public :
            Num()
            {
                count ++;
                cout<<"this is the time when ur constructor "<<count<<" is called"<<endl;
            }
            ~Num()
            {
                cout<<"this is the time when ur destructor "<<count <<" is called "<<endl;
                count--;

            }
};
int main()
{   
    cout<<"We have entered the main function"<<endl;
    Num n1;
    {
        cout<<"We have entered in num n1 object"<<endl;
        cout<<"Creating new object num n1"<<endl;
        cout<<"Creating two new objects in num n1"<<endl;
        Num n2,n3;
        cout<<"We are exiting the num 1 object"<<endl;
        cout<<"Back in the man function"<<endl;    
        return 0;
    }

}