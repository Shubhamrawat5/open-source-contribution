#include <iostream>
#include <string.h>
#include <stack> // Standard library for creating stack

using namespace std;

void reverse(char *str, int len)
{
 stack<char> s;
 int i;
 
 // Push into a stack
 for(i = 0; i < len; i++)  
  s.push(str[i]);
 
 // Pop from a stack   
 for(i= 0; i < len; i++)
 {
  str[i] = s.top();
  s.pop();
 }
 
}

int main()
{

   char str[]="Hello World";
   int len = strlen(str);
   
   reverse(str, len);
   
   cout <<"After reversing \n" << str;
   
   return 0;
}
