#include <iostream>
using namespace std;
class number {
int x;
public:
void input(int a){
    x=a;
}

void operator ++ (){
    x+=5;
    cout<<"Value of x after update:"<<x<<endl;
}


};
int main()
{

    number n1;
    n1.input(4);
    ++n1;
    int x=7;
    ++x;
    cout<<x;
return 0;
}
