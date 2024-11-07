//union are used to save the memory space
#include<iostream>
#include<iomanip>
using namespace std;
union Student
{
    int no;
    char div;
    float marks;
};
int main()
{
    union Student s1;
    s1.no=21;
    s1.div='a';
    s1.marks=85.5;
    cout<<"Number : "<<s1.no << endl;
    cout<<"Division : "<<s1.div << endl;
    cout<<"Marks : "<<s1.marks<<endl;
    return 0;
}
//the union only allow one of the team to get access i.e the lastone