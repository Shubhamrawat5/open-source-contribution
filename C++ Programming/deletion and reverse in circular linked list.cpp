
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};


void printList(struct Node *head) {
    if (head != NULL) {
        struct Node *temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
    } else {
        cout << "empty" << endl;
    }
    cout << endl;
}



class Solution {
  public:
    
    Node* reverse(Node* head) {
        
        Node *curr=head->next, *prev=head, *nxt=NULL;
        while(curr!=head){
            nxt=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nxt;
        }
        head->next=prev;
        return prev;
    }

    
    Node* deleteNode(Node* head, int key) {
    
        Node *temp = head->next, *prev=head;
        if(head->data==key){
            while(temp!=head){
                prev=temp;
                temp=temp->next;
            }
        }
        else{
            while(temp!=head and temp->data!=key){
                prev=temp;
                temp=temp->next;
            }
        }
        if(head->data==key or temp!=head)
        prev->next=temp->next;
        return head->data==key?prev->next:head;
    }

};


int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;

      
        while (ss >> number) {
            arr.push_back(number);
        }

        int key;
        cin >> key;
        cin.ignore();

        struct Node *head = new Node(arr[0]);
        struct Node *tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            tail->next = new Node(arr[i]);
            tail = tail->next;
        }
        tail->next = head; 

        Solution ob;

        head = ob.deleteNode(head, key);

        head = ob.reverse(head);

        
        printList(head);
    }
    return 0;
}
