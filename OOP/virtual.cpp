#include <iostream>
using namespace std;
class num{
         protected:
            int x=45;
        public:
        void setx(){
            x=56;
        }
         void dis(){
            cout<<"Value of a is :"<<x<<endl;
       }
};
class deri1 :virtual  public num{
         protected:
            int y=1;
       
   
        void sety(){
           
            y+=658;
        }
       
};
class deri2 : virtual  public num{
         protected:
            int z;
        public:
        void setz(int m){
            z=m;
        }
         void inc(){
            z+=45;
       }
       void up(){
        cout << "new value is:"<<z<<endl;
       }
};

class newderi : public   deri1 ,  public  deri2{

    public:
    void show(){
        
                sety();
                cout<< y <<endl;
                setz(564);
                cout<<z;
                dis();
         


    }
};
int main()
{
    newderi n1;
    n1.show();
return 0;
}
