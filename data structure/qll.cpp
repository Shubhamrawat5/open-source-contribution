#include <iostream>
#include<malloc.h>
using namespace std;
typedef struct Node {
    int data;
    struct Node *next;
}node;

node *front =NULL;
node *rear=NULL;

void enqueue(int data){
    node *q=(node*)malloc(sizeof(node));
    if(q==NULL){
        cout<<"queue is full\n";
    }
    else{

    
    q->data=data;
    q->next=NULL;
    if (front ==NULL){
        front=rear=q;
        }

    else{
           rear->next=q;
           rear=q;

    }
}
}

int dequeue(){
    node *ptr=front;
    int data=ptr->data;
    front=ptr->next;
    free(ptr);
    return data;
}

void show_elements(){

    node *ptr;
    ptr=front;
    while (ptr!=NULL){
        cout<<ptr->data<<" ";
        ptr=ptr->next;
    }
}


int main()
{
  

    do{
        cout<<"\n\t\tQueue Implementation Using linked list \n";
        cout<<"1.Enqueue\n2.dequeue\n3.display\n4.Exit\n";
        char choice;
        cout<<"Enter operation:";
        cin>>choice;
        if(choice=='1'){
            int data;
            cout<<"Enter data:";
            cin>>data;
            enqueue(data);
        }
        else if (choice=='2'){
            cout <<  "Dequeued element is:"<< dequeue() <<endl;
        }
        else if (choice=='3'){
            show_elements();
        }
        else if(choice=='4'){
            break;
        }

        else {
            cout<<"invalid input\n";
        }

    }while (1);

return 0;
}
