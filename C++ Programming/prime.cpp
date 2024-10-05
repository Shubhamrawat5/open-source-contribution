#include <iostream>
#include <stdio.h>
#include<string.h>
using namespace std;
int main()
{

   char str[100] , str2[100];

   gets(str);
   strcpy(str2,str);
   strrev(str);
   if (strcmp(str , str2)==0){
    cout<<"string is  plaindrome";
   }
   else{
    cout<<"String is not  plaindrome";
   }



   cout<<endl<< strcmp("hello" , "Hello");







   
return 0;
}
