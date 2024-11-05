#include<iostream>
#include<iomanip>
#include<unordered_map>
using namespace std;

int Romantoint(string s){
    unordered_map<char,int> roman={
        {'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}
    };
    int total=0;
    int prevalue=0;
    for(char c : s)
    {
        int current = roman[c];
        if(current>prevalue){
            total +=current -2*prevalue;
        }
        else{
            total+=current;
        }
        prevalue=current;
    }
    return total;

}

int main()
{
    string s;
    cout<<"Enter the Roman value : ";
    cin>>s;
    cout<<"Total : "<< Romantoint(s);
}