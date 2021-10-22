#include<stdio.h>
#include<stdlib.h>

struct node{
int data;
struct node*next;
};
void printLL(struct node*p){
  while(p!=NULL){
    printf("%d",p->data);
    p=p->next;
  }
}

int main()
{
  // node init
  struct node*head;
  struct node*one;
  struct node*two;
  struct node*three;
  // malloc
  one=malloc(sizeof(struct node));
  two=malloc(sizeof(struct node));
  three=malloc(sizeof(struct node));
  // assignment and link
  
  one->data=1;
  one->next=two;

  two->data=2;
  two->next=three;

  three->data=3;
  three->next=NULL;

  //save head as first node;
  head=one; 
  return 0;
}