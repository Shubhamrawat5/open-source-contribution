#include <iostream>
using namespace  std;
class number {

    int x, y , res , sum;
    public:
    void input(int x, int y){
        this->x=x;
        this->y=y;
    }
    void product(number n1 , number n2){
        res=n1.x*n2.x;
        sum=n1.y+n2.y;
    }
    void display (){
        cout <<"Product is :" << res<<endl;
        cout <<"Sum is :"<< sum<<endl;
    }
};

using namespace std;
int main()
{
    number n1 , n2 , n3;
    n1.input(1,2);
    n2.input(2,3);
    n3.product(n1 , n2);
    n3.display();
return 0;
}
