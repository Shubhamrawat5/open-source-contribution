#include <iostream>
using namespace std;

class  complex{

    int x, y ;
    public:
    complex(){}
    complex(int a , int b){
             x=a;
             y=b;
    }
    void sum(complex , complex);
    void difference(complex , complex);
    void product(complex , complex);

    void display(){

        cout<<"real:"<<x <<"\n img part:"<<y<<endl;
    }
};


void complex:: sum (complex c1 , complex c2){
     
     x=c1.x+c2.x;
     y=c1.y+c2.y;
     cout <<"sum of complex numbers:\n";
     cout<<"real:"<<x <<" img part:"<<y<<endl;




}
void complex:: difference (complex c1 , complex c2){
        x=c1.x-c2.x;
     y=c1.y-c2.y;
     cout <<"difference of complex numbers:\n";
     cout<<"real:"<<x <<" img part:"<<y<<endl;

    
}
void complex:: product (complex c1 , complex c2){
    cout <<"product of complex numbers:\n";
        x=c1.x*c2.x;
     y=c1.y*c2.y;
cout<<"real part :"<<x <<"  img part:"<<y<<endl;
    
}
int main()
{

complex c1 (2,3);
complex c2(1,4);
complex c3;
c3.product(c1,c2);
c3.sum(c1,c2);
c3.difference(c1,c2);



return 0;
}
