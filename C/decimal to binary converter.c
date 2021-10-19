
#include<stdio.h>
#include<stdlib.h>
#define TRUE 1
#define FALSE 0
# define STACKSIZE 100

 struct stack{
 int item[STACKSIZE];
 int TOP;
 };
 struct stack S;
 /****************************/
void IntialiseStack(void){
S.TOP=-1;
}
/****************************/
int IsEmpty(void){
if(S.TOP==-1)
  return TRUE;
else
   return FALSE;}
/****************************/
void Push(int x){
if(S.TOP==STACKSIZE-1){
  printf("stack overflow");
   exit(1);}
else
  S.TOP=S.TOP+1;
  S.item[S.TOP]=x;  }
/****************************/
int Pop(void)
{
int x;
if(IsEmpty()){
  printf("\nstack underflow");
   exit(1);}
else{
x=S.item[S.TOP];
S.TOP=S.TOP-1;}
return x;
}
/****************************/
int StackTop(void){
int x;
x=S.item[S.TOP];
return x;}








int main(){
int N,r,x;
IntialiseStack();
printf("enter a number");
scanf("%d",&N);
while(N!=0){
r=N%2;
Push(r);
N=N/2;}
while(!IsEmpty()){
x=Pop();
printf("%d",x);}
return 0;}
