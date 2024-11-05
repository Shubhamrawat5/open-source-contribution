#include<iostream>
using namespace std;

int main()
{
    int a = 10;
    int *ptr = &a;
    cout<<"Value of a : "<<*ptr<<endl;
    cout<<"Value of a : "<<a<<endl;
    //"new" -->> operator
    int *ptr1 = new int;
    int *ptr2 = new int(6);
    int *array = new int[3]; 
    array[0]=6;
    array[1]=7;
    array[2]=8;
    *ptr1 = 20;
    cout<<"Value of ptr1 : "<<*ptr1<<endl;
    cout<<"Value of ptr1 : "<<ptr1<<endl;
    cout<<"Value of ptr2 : "<<*ptr2<<endl;
    cout<<"Value of ptr2 : "<<ptr2<<endl;
    cout<<"Value at array[0] : "<<array[0]<<endl;
    cout<<"Value at array[1] : "<<array[1]<<endl;
    cout<<"Value at array[2] : "<<array[2]<<endl;
    cout<<"Value of array : "<<array<<endl;    
    //"delete" -->> operator
    delete array;
    delete ptr1;
    delete ptr2;    
    cout<<"Delete operator is called "<<endl;
    cout<<"Value of ptr1 : "<<*ptr1<<endl;
    cout<<"Value of ptr1 : "<<ptr1<<endl;
    cout<<"Value of ptr2 : "<<*ptr2<<endl;
    cout<<"Value of ptr2 : "<<ptr2<<endl;
    cout<<"Value at array[0] : "<<array[0]<<endl;
    cout<<"Value at array[1] : "<<array[1]<<endl;
    cout<<"Value at array[2] : "<<array[2]<<endl;
    cout<<"Value of array : "<<array<<endl;
    return 0;
}