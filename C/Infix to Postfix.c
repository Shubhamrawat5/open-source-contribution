#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>

struct node {
    int data;
    struct node *link;
};
struct node *head=NULL;
void push(char x) {
    struct node* p=(struct node*) malloc (sizeof(struct node));
    if(p==NULL)
    {
        printf("overflow");
        return;
    }
    p->data=x;
    p->link=head;
    head=p;
}

char pop() {
    char item;
    struct node *p;
    if(head==NULL)
        return -1;
    item=head->data;
    p=head;
    head=head->link;
    free(p);
    return item;
}

int match(char x) {
   switch (x)
   {
       case '+':
       case '-':
           return 1;
       case '*':
       case '/':
           return 2;
       case '^':
           return 3;
   }
    return -1;
}

void check() {
    char value,arr[10000];
    scanf("%s",arr);
    int i=0;
    while(arr[i])
    {
        value=arr[i];
        if((value>='a'&&value<='z')||(value>='A'&&value<='Z'))
            printf("%c",value);
        else if(value=='(')
            push(value);
        else if(value==')'){
            while(head!=NULL&&head->data!='(')
                printf("%c",pop());
            if (head!=NULL&&head->data!='(')
                printf("invalid");
            else
                pop();
        }
        else
        {
            while(head!=NULL&&(match(head->data)>=match(value)))
                printf("%c",pop());
            push(value);
        }
        i++;
    }
    while(head!=NULL)
        printf("%c",pop());
}

int main() {
    (check());
    printf("\n");
    return 0;
}
