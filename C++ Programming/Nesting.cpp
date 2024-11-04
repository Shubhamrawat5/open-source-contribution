#include<iostream>
#include<iomanip>
#include<string>
using namespace std;
class Binary
{
    string s;
    public :
    void check(void);
    void write(void);
    void one(void);
    void display(void);
};
void Binary::write(void)
{
    cout<<"Enter Binary no.:";
    cin>>s;
}
void Binary::check(void)
{
    for(int i = 0;i<s.length();i++)
    {
        if(s.at(i)!='0' && s.at(i)!='1')
        {
            cout<<"Not a binary no."<<endl;
            exit(0);
        }
    }
}
void Binary::one(void)
{
    for(int i= 0;i<s.length();i++)
    {
        if(s.at(i)=='0')
        {
            s.at(i)='1';
        }
        else{
            if(s.at(i)=='1')
        {
            s.at(i)='0';
        }
        }
    }
}
void Binary :: display(void)
{
    for(int i  = 0;i<s.length();i++)
    {
        cout<<s.at(i);
    }
}
int main()
{
    Binary B;
    B.write();
        B.check();
        B.one();
        B.display();
}