#include <iostream>
#include<stdlib.h>
using namespace std;
struct node {

    int data;
    struct node *next;
};

struct node*  insert_head(struct node  * head ,  int data){

         struct node *new_node=(struct node*)malloc(sizeof(struct node));
         struct node *ptr=head;
         new_node->data=data;
         new_node->next=head;
        
         while (ptr->next!=head){
            ptr=ptr->next;
         }
       
         ptr->next=new_node;
         
         head=new_node;
         return head;




} 
struct node*  insert_end(struct node  * head ,  int data){

         struct node *new_node=(struct node*)malloc(sizeof(struct node));
         struct node *ptr=head;
         new_node->data=data;
         while (ptr->next!=head){

            ptr=ptr->next;
         }
         new_node->next=ptr->next;
         ptr->next=new_node;




} 
void insert_at (struct node* head , int idx , int val){

     struct node *new_node=(struct node*)malloc(sizeof(struct node));
     int i=0;
     struct node *ptr=head;
     new_node->data=val;
     while (i<idx){
        ptr=ptr->next;
        i++;
     }
     new_node->next=ptr->next;
     ptr->next=new_node;
}

void display(struct node *head){
    struct node *ptr=head;
    do {
        cout<<ptr->data<<endl;
        ptr=ptr->next;
    }while(ptr!=head);
}
int main()
{

    struct node *head , *second , *third ;
    head=(struct node * )malloc(sizeof(struct node));
    second=(struct node * )malloc(sizeof(struct node));
    third =(struct node * )malloc(sizeof(struct node));
    head->data=11;
    head->next=second;
    second->data=12;
    second->next=third;
    third->data=13;
    third->next=head;
    struct node*ptr=head;
    
    head=insert_head(head , 44);
    insert_end(head,122);
     insert_at(head,3,1000);
   
    display(head);
  
return 0;
}
