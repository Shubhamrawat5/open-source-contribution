// Header File
#include<iostream>
using namespace std;

// Structure of Linked List
struct Node{
    int data;
    Node *next;
    Node(int val){
        data = val;
        next = NULL;
    }
};

// Utility function to print the linked list
void display(Node* head){
    while(head != NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<"\n";
}

// Function to reverse the linked list recursively
Node* reverse(Node* head,Node* prev){
    if(head == NULL)
        return prev;
    
    Node* next = head->next;
    head->next = prev;
    return reverse(next,head);
}

int main(){
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    cout<<"Original linked list "<<"\n";
    display(head);
    Node* newHead = reverse(head,NULL);
    cout<<"Reversed Linked list "<<"\n";
    display(newHead);
}

