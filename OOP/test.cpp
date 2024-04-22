#include <iostream>
#include <sstream>
#include <string.h>
using namespace std;

/*
Enter code for class Student here.
Read statement for specification.
*/
class Student{
    public:
    int age , standard;
    string first_name , last_name;
    int  set_age(int a){
        age=a;
    }
    int set_standard(int std){
        standard=std;
    }
    char set_first_name(string nm){
        first_name=nm;
    }
    char set_last_name(string ln){
        last_name=ln;
    }
     int  get_age(void){
        return age;
    }
    int get_standard(void){
       return standard;
    }
   string get_first_name(void){
       return first_name;
    }
    string get_last_name(void){
        return  last_name;
    }
};

int main() {
    int age, standard;
    string first_name, last_name;
    
    cin >> age >> first_name >> last_name >> standard;
    
    Student st;
    st.set_age(age);
    st.set_standard(standard);
    st.set_first_name(first_name);
    st.set_last_name(last_name);
    
    cout << st.get_age() << "\n";
    cout << st.get_last_name() << ", " << st.get_first_name() << "\n";
    cout << st.get_standard() << "\n";
    cout << "\n";
    // cout << st.to_string();
    
    return 0;
}
