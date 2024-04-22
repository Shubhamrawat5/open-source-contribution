#include <iostream> 
#include<malloc.h>
using namespace std;
typedef struct create_node 
{
   int data ;
   struct create_node *next;
}node ;

node *rear=NULL; 
node *front=NULL;


void enque(int data){
    node *q1=(node *)malloc(sizeof(node)); 
    
    q1->data=data;
    q1->next=NULL;

   
    if (front==NULL){
        front=rear=q1;
    }
    else{
           rear->next=q1;
           rear=q1;
    }

    cout<<data <<"is inserted\n";

    
}

int dequeue(){
    node *temp=(node *)malloc(sizeof(node)); 
    temp=front;
    int dat=temp->data;
    front=front->next;
    free(temp);
    cout<<"poped element is:"<< dat<<endl;
}

void dis(){

    node *temp=front;
    while (temp!=NULL){
        cout<<temp->data<<endl;
        temp=temp->next;
    }
}
int main()
{
  
  enque(44);
  enque(45);
  enque(46);
  enque(47);
//   dequeue();
 
//   dequeue();
   cout<<"\n\n";
  dis();
  
return 0;
}
