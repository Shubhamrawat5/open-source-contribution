#include <iostream>
#include<stdlib.h>
#include<cstring>
using namespace std;
struct stack  {

    int data;
    struct stack *next;
};

struct stack * top=NULL;


void push( char m){

    struct stack *p = (struct stack*)malloc(sizeof(struct stack));
    p->data=m;
    p->next=top;
    top=p;





}

int  pop(){

    struct stack *q ;
    int dat;
    q=top;
    dat=q->data;
    top=top->next;
    free(q);
    return dat;

}


int match(char a , char b){


    if (a=='(' && b==')')
       return 1;
       
    else if (a=='[' && b==']')
       return 1;
       
   else  if (a=='{' && b=='}')
       return 1;
       
   else
       return 0;
}

int parant(char str[]){
int i=0;
 while (str[i]!='\0'){
           

           if (str[i]=='(' || str[i]=='['|| str[i]=='{' ){

            push(str[i]);
           }

           else  if (str[i]==')' || str[i]==']'|| str[i]=='}'){
            
             if (top==NULL){
                return 0;
            }
             int pch=pop();
             if ( !match(pch , str[i])){
                 return 0;
           }
            
           }


     i++;
 }

 if (top==NULL)
 {
 return 1;
 }
 else 
 return 0;
    





}


int main()
{

    char str[50];
    gets(str);
    int res=parant(str);
    if (res==1){
        cout<<"Expression is balanced\n";

    }
    else {
        cout <<"Expression is not balanced";
    }
    
  
return 0;
}
