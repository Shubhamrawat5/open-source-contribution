#include<iostream>
#include<iomanip>
using namespace std;
struct food
{
    int quantity;
    char name;
    float price;
};

int main()
{
    struct food Lunch;
    struct food Breakfast;
    cout<<"Enter the quantity of food : ";
    cin>>Lunch.quantity;
    cout<<"Enter the Starting letter of food : ";
    cin>>Lunch.name;
    cout<<"Enter the prince of food : ";
    cin>>Lunch.price;
    cout<<endl<<"Quantity of Lunch : "<<Lunch.quantity<<endl;
    cout<<"Starting letter of Lunch : "<<Lunch.name<<endl;
    cout<<"Price of Lunch: "<<Lunch.price<<endl;
    cout<<"Enter the quantity of food : ";
    cin>>Breakfast.quantity;
    cout<<"Enter the Starting letter of food : ";
    cin>>Breakfast.name;
    cout<<"Enter the prince of food : ";
    cin>>Breakfast.price;
    cout<<endl<<"Quantity of Breakfast : "<<Breakfast.quantity<<endl;
    cout<<"Starting letter of Breakfast : "<<Breakfast.name<<endl;
    cout<<"Price of Breakfast : "<<Breakfast.price<<endl;
    
    return 0;
}
