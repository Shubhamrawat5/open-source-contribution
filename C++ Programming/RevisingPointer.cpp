#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
    int a = 4;
    int *ptr= &a;
 	int *array = new int[3];
    cout << "Value of a: " << a << endl;
    cout << "Address of a: " << &a << endl;
    cout << "Value of ptr: " << ptr << endl;
    cout << "Dereferenced value of ptr: " << (*ptr)<< endl;
    int *p = new int(40);
    cout<<"The value at p is "<<(*p)<<endl; 
	array[0]=10;
    array[1]=20;
    array[2]=30; 
	cout <<"The Value at array[0] is " << array[0] << endl;
	cout <<"The Value at array[1] is " << array[1] << endl;
	cout <<"The Value at array[2] is " << array[2] << endl;
    return 0;
}