#include <iostream>
#include<stdlib.h>
using namespace std;
typedef struct queue {

int front , rear;
int *arr;
int size;

} que;

void push (que *q1 , int data){

    if(q1->rear==q1->size-1){
        cout<<"queue is full\n";
    }
    else {
         if (q1->front ==-1){

            q1->front++;
            q1->rear++;
            q1->arr[q1->rear]=data;

         }
         else{
               q1->rear++;
            q1->arr[q1->rear]=data;
         }
    }
}


void pop(que *q1){

    if (q1->front==-1){

        cout<<"underflow\n";

    }
    else {
        q1->front++;
    }

    
}


void dis(que *q1){
if (q1->front==-1){

        cout<<"empty\n";

    }
    else{

        for (int  i = q1->front ; i <= q1->rear; i++)
        {
            cout<<q1->arr[i]<<" ";
        }
        cout<<endl;
        
    }


}
int main()
{

   que *q1;
   q1->size=10;
   q1->front=-1;
   q1->arr= (int*) malloc(q1->size*sizeof(int  ));
   q1->rear=-1;
   push(q1 , 45);
   push(q1 , 46);
   push(q1 , 48);
   dis(q1);
   pop(q1);
   dis(q1);



return 0;
}
