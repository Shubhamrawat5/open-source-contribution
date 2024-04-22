#include <iostream>
#include<stdlib.h>
using namespace std;
struct node {
    int data;
    struct node* next;
};


struct node *top=NULL;


void push(int data){
     struct node *p=(struct node* )malloc(sizeof(struct node));
    if (p==NULL){
        cout<<"stack is full\n";
    }
    else {
         
        
         p->data=data;
         p->next=top;
         top=p;
        
    }

}

void pop(){

     if (top==NULL){
        cout<<"Stack is empty\n";

     }
     else {

        struct node *temp=top;
        top=top->next;
        free(temp);
     }


}

void display(){
    if (top==NULL){
        cout<<"No elements in stack\n";
    }
    else {

        struct node* temp;
        temp=top;
        while (temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
    }
     



}
int main()
{
    push(11);
    push(12);
    push(13);
    push(14);
    push(15);
    display();
    pop();
    pop();
    cout<<endl;
    display();
return 0;
}
