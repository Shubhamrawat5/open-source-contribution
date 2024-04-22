#include <iostream>
using namespace std;

class base {
    
    
    public:
    int x;
    void input(int b ){
        x=b;
    }

};

class derived1 :public base {

    
  
    public:
      int y ;
    void get_val1(int b){
        y=b;
    }
    void sum_1(){
        cout<<"Sum from derived class 1: "<<x+y<<endl;
    }
};

class derived2 :public base {

   
    
    public:
    int z;
    void  get_val2(int b){
        z=b;
    }
    void sum_2(){
        cout<<"Sum from derived class 2: "<<x+z<<endl;
    }
};

class derived3 : public derived1 , public derived2 {
    int k;
    public:
    void get_va3(int b){
        k=b;
    }
    void sum_hyb(derived1 d1 , derived2 d2){
         cout<<"Sum from hybrid class: "<<d1.y+d2.z+k<<endl;
    }

};
int main()
{

    derived1 d1;
    derived2 d2;
    derived3 d3;
    d1.input(2);
    d1.get_val1(3);
    d1.sum_1();
    d2.input(5);
    d2.get_val2(5);
    d2.sum_2();
    d3.get_val1(2);
    d3.get_val2(6);
    d3.get_va3(6);
    d3.sum_hyb(d1 , d2);
return 0;
}
