#include <iostream>
using namespace std;
class number {

public:
int a, b;
void input(int a , int b){


    this->a=a;
    this->b=b;
}

number  operator +( number n1 , number n2 , number n3 ){
    number n4;
    n4.a=a+n1.a+n2.a+n3.a;
    n4.b=b+n1.b+n2.b+n3.b;
  
    return n4;
}

// number operator > (number n1 , number n2 ){


//     number n3;
//     n3.a=a>n1.a;
//     n3.b=b>n1.b;
//     return n3;

// }

void display(){
    
  
    cout<<"Value of a : "<< a<<endl;
    cout<<"value of b :"<< b<<endl;
}


};
int main()
{

number n1,n2 , n3 ,n4;
n1.input(11,12);
n2.input(10,20);
n3.input(23,45);
n4.input(55,23);
number n4;
n3=n1+n2+n3+n4;

// if (n3.a==1){

//     cout<<n1.a <<">"<<n2.a<<endl;
// }
// else {

//  cout<<n1.a <<"<"<<n2.a<<endl;

// }

// if (n3.b==1){

//     cout<<n1.b <<">"<<n2.b<<endl;
// }
// else {

//  cout<<n1.b <<"<"<<n2.b<<endl;

// }
n4.display();


return 0;
}
