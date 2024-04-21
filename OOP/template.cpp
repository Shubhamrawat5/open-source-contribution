#include <iostream>
using namespace std;
template <class T , class M> 
class vector{
    
     public:
     int  size;
     T *arr;
     M ch;
     vector(int  size , M c)
     {
         this->size=size;
         arr=new T[size];
         ch=c;
     }

     T  sum(vector v){
          T d=0;
        for (int  i = 0; i < size; i++)
        {
            d+=this->arr[i]*v.arr[i];
        }
        cout << this->ch;

        return d;
        
     }



};
int main()
{

    vector <float , char> v1(2 ,'a'), v2(2,'b');
    v1.arr[0]=1.3;
    v1.arr[1]=2.5;
   
    v2.arr[0]=41.3;
    v2.arr[1]=5.0;


    float  v3=v2.sum(v1);
    cout << v3;

 
    
return 0;
}
