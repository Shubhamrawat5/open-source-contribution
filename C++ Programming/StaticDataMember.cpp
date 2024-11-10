#include<iostream>
#include<iomanip>
using namespace std;
class Student
{
    int roll;
    static int count;
     
    public :
    void setData(void)
    {
        cout<<"enter the roll no.: ";
        cin>>roll;
        count++;
    }
    void getData(void)
    {
        cout<<"Roll No.:"<<roll<<endl<<"The count : "<<count<<"."<<endl;
    }
};

int Student :: count=100;
int main()
{
    Student S;
    Student P;
    Student K;


    S.setData();
    S.getData();


    P.setData();
    P.getData();

    
    K.setData();
    K.getData();

}