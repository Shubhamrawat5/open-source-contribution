#include <iostream>
#include <stdlib.h>
using namespace std;

typedef struct queue_code
{

    int size;

    int front, rear;
    int *arr;
} queue;
void push(queue *q1 , int data){
    if ((q1->rear+1)%q1->size==q1->front){
        cout<<"queue is Full\n";
    }
    else {
        if (q1->front==-1){
            q1->front=0;
        }
        q1->rear=(q1->rear+1)%q1->size;
        q1->arr[q1->rear]=data;
        cout<<data << "  is pushed to queue \n";


    }
}

void pop(queue *q1){

    if (q1->rear==-1 && q1->front==-1){
        cout<<"queue is emmpty\n";
    }
    else if (q1->front==q1->rear){
        cout<<"\n"<<q1->arr[q1->front]<<"  is poped from queue \n";
        q1->front=q1->rear=-1;
    }
    else{
        cout<<"\n"<<q1->arr[q1->front]<<"  is poped from queue \n";
        q1->front=(q1->front+1)%q1->size;

    }
}

void display (queue *q1){
    if (q1->front==-1){
        cout<<"empty queue , no elements to display\n";
    }

    else {
        for (int  i = q1->front; i != q1->rear ; i=(i+1)%q1->size)
                {
            cout<< q1->arr[i]<< " ";
        }
        
    }
}

int main()
{

    queue *q1 = (queue *)malloc(sizeof(queue));
    q1->size = 8;
    q1->front = -1;
    q1->rear = -1;
    q1->arr = (int *)malloc(q1->size * sizeof(int));

    push (q1 , 44);
      push (q1 , 41);
        push (q1 , 46);
        
          push(q1,33);
           
            push (q1 , 144);
      
           pop(q1); 
              pop(q1);   
                 pop(q1);  
                    pop(q1);  
                       pop(q1);  
          display(q1);

    
    return 0;
}
