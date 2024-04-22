#include <iostream>
using namespace std;

class stu_info
{

public:
    int cls, fees;

    void get_info()
    {

        cout << "enter class:";
        cin >> cls;
        cout << "Enter fees of student:";
        cin >> fees;
    }

    void dis()
    {

        cout << "Class is :" << cls << endl;
        cout << "Fees is:" << fees << endl;
    }
};

class student
{

    string name;
    int id;
    stu_info s1;

public:
    void get_info(stu_info &stu)
    {
        cout << "Enter name:";
        cin >> name;
        cout << "Enter student ID :";
        cin >> id;
        s1 = stu;
    }

    void dis()
    {

        cout << "\t\tStudent information\n";
        cout << "Name is:" << name << endl;
        cout << "ID is: " << id << endl;
        s1.dis();
    }
};
int main()
{

    stu_info s1;
    s1.get_info();

    student stu1;
    stu1.get_info(s1);
    stu1.dis();
    

    return 0;
}
