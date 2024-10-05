#include <iostream>
using namespace std;

class average{

        int  a,b,c;
        public:
        void input(){
            cout<<"Enter three numbers:";
            cin>>a>>b>>c;
        }
        
        friend void find_average(average);

};

void find_average(average a1){

    double avg=(a1.a+a1.b+a1.c)/3;
    cout<<"Average is :"<<avg;
}

int main()
{

    average a1;
    a1.input();
   find_average(a1);

return 0;
}
