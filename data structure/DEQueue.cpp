#include <iostream>
#include <stdlib.h>
using namespace std;

typedef struct queue_code
{

    int size;

    int front, rearf;
    int frontr, rear;
    int *arr;
} queue;

void enqueue_rear(queue *q1, int data)
{

    if (q1->rear == q1->size - 1)
    {
        cout << "overflow" << endl;
    }
    else
    {
        if (q1->front == -1)
        {
            q1->front = 0;
        }
        q1->rear += 1;
        q1->arr[q1->rear] = data;
        cout << data << "is enqueued from rear\n";
    }
}

void dequeue_front(queue *q1)
{

    if (q1->rear == -1)
    {
        cout << "no element to pop\n";
    }
    else
    {
        int dat = q1->arr[q1->front];
        q1->front += 1;
        cout << dat << "is dequeued from front  \n";
    }
}
 void enqueue_front(queue *q1 , int data){

    if (( q1->front==0 && q1->rear==q1->size-1) ||  q1->front== q1->rear+1){
        cout<<"overflow\n";
    }

   else  if (q1->front==-1 && q1->rear==-1){
        q1->front=q1->rear=0;
       
    }
    else if (q1->front==0){
        q1->front=q1->size-1;
    }
    else {
        q1->front-=1;
    }
    q1->arr[q1->front]=data;

 }

void dequeue_rear(queue *q1){

    if (q1->rear==-1){
        cout<<"no elements\n";

    }
    else {
        int dat=q1->arr[q1->rear];
        q1->rear--;
        cout<< dat<<"is removed\n";
    }
}





void display(queue *q1)
{

    if (q1->rear == -1)
    {
        cout << "no element to display\n";
    }
    else
    {

        for (int i = q1->front; i <= q1->rear; i++)
        {
            cout << q1->arr[i] << " ";
        }
        cout<<endl;
    }
}
int main()
{

    queue *q1 = (queue *)malloc(sizeof(queue));
    q1->size = 4;
    q1->front = q1->frontr = q1->rearf = q1->rear = -1;
    q1->arr = (int *)malloc(sizeof(int));
    enqueue_rear (q1, 34);
    enqueue_rear(q1, 35);
   
   enqueue_front(q1,44);
   dequeue_rear(q1);
   dequeue_front(q1);

    display(q1);
    

    // enqueue_rear(q1, 37);
  
    // dequeue_front(q1);
    //     dequeue_front(q1);
    //     enqueue_front(q1, 137);
    //     dequeue_rear(q1);

    

    return 0;
}
