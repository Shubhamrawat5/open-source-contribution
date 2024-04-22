#include <iostream>
#include <stdlib.h>
using namespace std;

typedef struct queue_code
{

    int size;

    int front, rear;
    int *arr;
} queue;

void push(queue *q1, int data)
{

    if (q1->rear == q1->size - 1)
    {
        cout << "overflow" << endl;
    }
    else
    {
        if (q1->front ==-1){
            q1->front=0;
        }
        q1->rear += 1;
        q1->arr[q1->rear] = data;
    }
}

void pop(queue *q1)
{

    if (q1->front > q1->rear)
    {
        cout << "no element to pop\n";
    }
    else
    {

        q1->front++;
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
    }
}
int main()
{

    queue *q1 = (queue *)malloc(sizeof(queue));
    q1->size = 15;
    q1->front = 0;
    q1->rear = -1;
    q1->arr = (int *)malloc(q1->size * sizeof(int));
    push(q1, 45);
    push(q1, 35);
    push(q1, 15);
    push(q1, 55);
    push(q1, 155);
    push(q1, 45);
    push(q1, 35);
    push(q1, 15);
    push(q1, 55);
    push(q1, 155);
    push(q1, 45);
    push(q1, 35);
    push(q1, 15);
    push(q1, 55);
    push(q1, 155);
    push(q1, 155);

       pop(q1);
    //    pop(q1);
    //    pop(q1);

    //     pop(q1);

    display(q1);
    return 0;
}
