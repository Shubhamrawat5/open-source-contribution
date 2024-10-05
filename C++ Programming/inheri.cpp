#include <iostream>
using namespace std;

class person
{
protected:
    string name;
    string id;

public:
    void get_info()
    {
        cout << "Enter name:";
        cin >> name;
        cout << "Enter ID:";
        cin >> id;
    }
};

class student : public person
{
    int cls;
    int fees;

public:
    void get_stu_data()
    {
        cout << "Enter class of student:";
        cin >> cls;
        cout << "Enter fees:";
        cin >> fees;
    }

    void display()
    {
        cout << "\n\nStudent details\n\n";
        cout << "name:" << name << endl;
        cout << "ID:" << id << endl;
        cout << "class:" << cls << endl;
        cout << "fees:" << fees << endl;
    }
};

class employee : public person
{

    string dept;
    int slry;

public:
    void get_emp_data()
    {
        cout << "Enter department of employee:";
        cin >> dept;
        cout << "Enter salary :";
        cin >> slry;
    }

    void display()
    {
        cout << "\n\nEmployee details\n\n";
        cout << "name:" << name << endl;
        cout << "ID:" << id << endl;
        cout << "department:" << dept << endl;
        cout << "salary:" << slry << endl;
    }
};
int main()
{

    student s1;
    employee e1;
    cout << "Enter Student details\n";
    s1.get_info();
    s1.get_stu_data();
    cout << "\n\nEnter Employee details\n";
    e1.get_info();
    e1.get_emp_data();
    s1.display();
    e1.display();
    return 0;
}
