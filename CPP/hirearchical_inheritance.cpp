#include <iostream>
using namespace std;

//A fun example of hireachical inheritance
/*
Here four classes are taken
where all the base class animal is being inherited to rest 3 derived classes only

diagram:
                            [animal]
                            /   |   \
                           /    |    \
                          /     |     \
                        reg   eat_w  is_d
*/


class animals{
    protected:
    string animalTypes[5] = {"horse","cow","goat","lion","tiger"};
};

class region:public animals{
    public:
    void get_region(){
        for(int i = 0;i<5;i++){
            if(i<3){
                cout<<animalTypes[i]<<" lives on field"<<endl;
            }
            else{
                cout<<animalTypes[i]<<" lives on forest"<<endl;
            }
        }
    }
};

class eats_what:public animals{
    public:
    void get_food(){
        for(int i = 0;i<5;i++){
            if(i<3){
                cout<<animalTypes[i]<<" eats grass"<<endl;
            }
            else{
                cout<<animalTypes[i]<<" eats meat"<<endl;
            }
        }
    }
};


class is_dangerous:public animals{
    public:
    void check_friendliness(){
        for(int i = 0;i<5;i++){
            if(i<3){
                cout<<animalTypes[i]<<" friendly"<<endl;
            }
            else{
                cout<<animalTypes[i]<<" dangerous"<<endl;
            }
        }
    }
};


main(){
    region r1;
    eats_what r2;
    is_dangerous r3;

    int choice;
    cout<<"press 1 to see regions 2 to see food 3 to see dangerous or not: ";
    cin>>choice;

    switch(choice){
        case 1:
        r1.get_region();
        break;
        case 2:
        r2.get_food();
        break;
        case 3:
        r3.check_friendliness();
        break;
        default:
        cout<<"invaid choice";
    }
}
