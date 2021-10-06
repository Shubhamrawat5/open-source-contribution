#include<stdio.h>
#include<stdlib.h>

struct node {

  struct node * prev;
  int data;
  struct node * next;

}

int main() {
  int i, d, n;
  struct node * a1 = (struct node *)malloc(sizeof(struct node));
  struct node * a2 = (struct node *)malloc(sizeof(struct node));
  struct node * a3 = (struct node *)malloc(sizeof(struct node));
  struct node * a4 = (struct node *)malloc(sizeof(struct node));

  a1->data = 140;
  a1->prev = NULL;
  a1->next = a2;

  a2->data = 193;
  a2->prev = a1;
  a2->next = a3;

  a3->data = 194;
  a3->prev = a2;
  a3->next = a4;

  a4->data = 195;
  a4->prev = a3;
  a4->next = NULL;


  return 0;
}
