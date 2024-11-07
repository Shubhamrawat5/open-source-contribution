#include<iostream>
#include<iomanip>
using namespace std;

bool match(char l,char c){
    return (l=='{'&&c=='}')||(l=='['&&c==']')||(l=='('&&c==')');
}

bool isValid(string s){
string stk;
for(char c:s){
    if(c=='{'||c=='('||c=='[')
    {
        stk.push_back(c);
    }
    else if(stk.empty() || !match(stk.back(),c)){
        return false;
    }
    else {
        stk.pop_back();
    }
}
    return stk.empty();
}


int main(){
    string s;
    cout<<"Enter the Paranthsis : ";
    cin>>s;
    // if (isValid(s)==0){
    //     cout<<"False";
    // }
    // else{
    //     cout<<"True";
    // }
    // return 0;
    string ans = isValid(s) ? "True":"False";
    cout<<ans<<endl;
    return 0;

}