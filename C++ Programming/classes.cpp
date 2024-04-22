#include <iostream>
#include <string.h>
using namespace std;
class person{

    string email , p_num;
    int slry;
    public:
         string name ;
         int age;
         void read_data(void){

              cout<<"Enter your name:";
              cin >> name;
              cout << "Enter your age:";
              cin >> age;
              cout << "Enter your Phone number:";
              cin>> p_num;
              cout << "Enter your email ID:";
              cin >> email;
              cout << "Enter your monthly pay:";
              cin >> slry;

         }
         void inc_slry(void){
            if (slry > 50000)
            {
                cout<< "No increment";
            }
            else
            {
                slry+=2000;
                cout<<"your salary after increment is :" << slry << endl;
            }
         }
          void display(void){

            cout << "Name is :" << name << endl;
            cout << "Age is :" << age << endl;
            cout << "Phone Number is :" << p_num << endl;
            cout << "Email ID  is :" << email << endl;
            cout << "Basic pay  is :" << slry << endl;
            inc_slry();
          }




};
int main()
{
    person p1;
    p1.read_data();
    p1.display();

    return 0;
}
