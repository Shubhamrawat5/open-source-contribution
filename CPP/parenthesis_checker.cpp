// Parenthesis checker
#include<iostream>
#include<stack>            // Header file of stack
using namespace std;

/* IDEA - "The last opened bracket has to be closed first for it to be balanced".
           This gives us the intuition of LIFO (last in first out) which has 
           to be implemented by stack.
   ALGORITHM - 
        (i)   We traverse the string of brackets.
        (ii)  If we encounter a opening bracket, then we push it in stack.
        (iii) Else (i.e closing bracket) we check that whether the closing
              bracket pairs up with the opening bracket at top of the stack.
              (that is we follow the LIFO order)
              (a) if they match then pop the element and continue
              (b) else return false
        Special case
              (a) if we encounter a closing bracket and the stack is empty.
                  This will happen in case of "(()))", when we will encounter
                  the last closing bracket,there won't be any opening bracket
                  in the stack (as both the opening brackets must have been 
                  popped before).
              (b) At the end if we have no element in the stack, then the brackets
                  are balanced.  
*/

bool check(char a,char b){          
    /* This function is used to check whether the closing bracket we encounter
       has a matching pair at the top of the stack or not */
    if(a == '(' && b == ')')           
        return true;                   
    if(a == '{' && b == '}')           
        return true;
    if(a == '[' && b == ']')
        return true;
    return false;
}
bool parenthesis_checker(string & str){
    // Function for parenthesis checking
    stack <char> s;        // declaration of stack
    for(int i = 0; i < str.length(); i++){
        if(str[i] == '(' || str[i] == '{' || str[i] == '[')
            s.push(str[i]);
        else{
            if(s.empty())
                return false;
            if(!check(s.top(),str[i]))
                return false;
            else
                s.pop();
        }
    }
    return s.empty();
}
int main(){
    string str1 = "[()]{}{()()}";
    string str2 = "[(])";
    string str3 = "(()))";
    parenthesis_checker(str1)? cout<<str1<<" - True"<<"\n" : cout<<str1<<" - False"<<"\n";
    parenthesis_checker(str2)? cout<<str2<<" - True"<<"\n" : cout<<str2<<" - False"<<"\n";
    parenthesis_checker(str3)? cout<<str3<<" - True"<<"\n" : cout<<str3<<" - False"<<"\n";
}