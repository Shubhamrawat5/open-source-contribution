#include <iostream>
using namespace std;

            
class numbers {

    int x , y , z;
    double m;
    public :
    numbers(){
        x=0;
        y=0 ;
        z=0;
        m=0;
    }
    numbers (int a , int b , int c){
        x=a;
        y=b;
        z=c;

    }
    numbers (int a , int b , double c){
        x=a;
        y=b;
        m=c;

    }
    void show (){
        cout << "x :" << x<< endl <<"y:" << y << endl << "z:"<< z <<endl << "m:" << m << endl; 
     }

};
int main()
{
    numbers n1 , n2(1,33,12) ,n3(4 , 2, 3.43);
    n1.show();
    n2.show();
    n3.show();


    



    
return 0;
}
