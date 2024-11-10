#include<iostream>
#include<iomanip>
using namespace std;

class student{
    protected :
    int rollno;
    public :
    void setrollno(int a ){
        rollno=a;
    }
    void printnumber(){
        cout<<"Your Roll no. : "<<rollno<<endl;
    }
};

class test : virtual public student {
    protected :
    float maths , physic ;
    public :
    void setmarks(float m1,float m2)
    {
        maths =  m1;
        physic = m2;
    }      
    void printmarks()
    {
        cout<<"Maths Marks : "<<maths<<endl;
        cout<<"Physic Marks : "<<physic<<endl;
    }
};

class sports : virtual public student {
    protected : 
    int score;
    public :
    void setscore(int s){ 
        score=s;
    }
    void printscore(){
        cout<<"Your Score : "<<score<<endl;
    }
};


class result : public test ,public sports{
    private :
    float total;
    public :
    void display(){
        printnumber();
        printmarks();
        printscore();
        total = maths + physic + score;
        cout<<"Your total Score  : "<<total<<endl;
    }
};
int main()
{
    result stu;
    stu.setrollno(39);
    stu.setmarks(89.7,98.6);
    stu.setscore(9);
    stu.display();
}