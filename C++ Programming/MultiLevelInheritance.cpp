#include<iostream>
#include<iomanip>
using namespace std;
class student{
    protected :
    int rollno ;
    public :
    void setrollno(int);
    void displayrollno(void);
};

void student :: setrollno(int r){
    rollno = r;
}
void student :: displayrollno(void)
{
    cout<<"Roll no.: "<<rollno<<endl;
}
class exam : public student 
{
    protected :
    float maths;
    float physic;
    public :
    void setmarks(float m1,float m2)
    {
        maths =m1;
        physic =m2;
    }
    void displaymarks(void)
    {
        cout<<"Maths Marks: "<<maths<<endl;
        cout<<"Physics Marks: "<<physic<<endl;
    }
};
class result:public exam
{
    float percent;
    public : 
        void diplayresult()
    { 
        displayrollno();
        displaymarks();
        cout<<"Your Percentage : "<<(maths+physic)/2<<endl;
    }
};

int main()
{
    result s1;
    s1.setrollno(1);
    s1.setmarks(99.99,90.0);
    s1.diplayresult();
 
}

/*
if we are inheriting b form a and c from b[a->b->c] 
1. a is the base class for b & b is the base class for c but b is also a derived class for a
2.a->b->c is called the inheritance path
*/