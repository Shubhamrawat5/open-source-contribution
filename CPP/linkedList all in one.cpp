#include <bits/stdc++.h>
using namespace std;

// use head as ref(&) for insertion and deletion
// Node* temp = head;

class Node{
    public: 
        int data;
        Node* next;
    Node(int x){
        data = x;
        next = NULL;
    }
};

void insertAtHead(Node* &head, int val){
    Node* n = new Node(val);
    n -> next = head;
    head = n;
}

void insertAtTail(Node* &head, int val){
    Node* n = new Node(val);
    if(head == NULL){
        head = n;
        return;
    }
    Node* temp = head;
    while(temp -> next != NULL){
        temp = temp -> next;
    }
    temp -> next = n;
    return;
}

void insertAtPosition(Node* &head, int pos, int val){
    Node* n = new Node(val);
    if(pos == 1){
        n -> next = head;
        head = n;
        return;
    }
    Node* temp = head;
    for(int i=0;i<pos-2;i++){
        temp = temp -> next;
    }
    n -> next = temp -> next;
    temp -> next = n;
    return;
}

Node* sortedInsert(Node* head, int val){
    Node* n = new Node(val);
    if(head == NULL){
        head = n;
        return head;
    }
    if(val < head -> data){
        n -> next = head;
        head = n;
        return head;
    }
    Node* temp = head;
    while(temp -> next != NULL && temp -> next -> data < val){
        temp = temp -> next;
    }
    n -> next = temp -> next;
    temp -> next = n;
    return head;
}

void deleteHead(Node* &head){
    if(head == NULL){
        return;
    }
    Node* toDelete = head;
    head = head -> next;
    delete toDelete;
    return;
}

void deleteMidNode(Node* &head, int val){
    Node* temp = head;
    while(temp -> next -> data != val){
        temp = temp -> next;
    }
    Node* toDelete = temp -> next;
    temp -> next = temp -> next -> next;
    delete toDelete;
}

void deleteTail(Node* head){
    if(head == NULL){
        return;
    }
    if(head -> next == NULL){
        delete head -> next;
        head = NULL;
    }
    Node* temp = head;
    while(temp -> next -> next != NULL){
        temp = temp -> next;
    }
    delete temp -> next;
    temp -> next = NULL;
    return;
}

// Recursively print all the nodes
// void recursionLL(Node* head){
//     if(head == NULL){
//         return;
//     }
//     cout << head -> data << " ";
//     recursionLL(head -> next);
//     return;
// }

// Recursive solution for searching in linked list
// int recSearch(Node* head, int val){
//     if(head == NULL){
//         return -1;
//     }
//     if(head -> data == val){
//         return 1;
//     }else{
//         int res = recSearch(head -> next, val);
//         if(res == -1){
//             return -1;
//         }else{
//             return res+1;
//         }
//     }
// }

bool searchList(Node* head, int key){
    while(head != NULL){
        if(head -> data == key){
            return true;
        }
        head = head -> next;
    }
    return false;
}

Node* reverseLL(Node* &head){
    Node* prevPtr = NULL;
    Node* currPtr = head;
    Node* nextPtr;
    while(currPtr != NULL){
        nextPtr = currPtr -> next;
        currPtr -> next = prevPtr;

        prevPtr = currPtr;
        currPtr = nextPtr;
    }
    return prevPtr;

}

Node* recursiveReverse(Node* curr, Node* prev){
    if(curr == NULL){
        return prev;
    }
    Node* next = curr -> next;
    curr -> next = prev;
    return recursiveReverse(next, curr);
}

void middleOfLL(Node* head){
    if(head == NULL){
        return;
    }
    if(head -> next == NULL){
        cout << head -> data << endl;
        return;
    }
    Node* slow = head;
    Node* fast = head;
    while(fast != NULL && fast -> next != NULL){
        slow = slow -> next;
        fast = fast -> next -> next;
    }
    cout << slow -> data << endl;
    return;
}

// Print Nth Node from end
void nFromLast(Node* head, int n){
    Node* first = head;
    Node* second = head;
    for(int i=0;i<n;i++){
        if(second == NULL){
            return;
        }
        second = second -> next;
    }
    while(second != NULL){
        first = first -> next;
        second = second -> next;
    }
    cout << first -> data << endl;
    return;
}

void removeDuplicates(Node* head){
    while(head != NULL && head -> next != NULL){
        if(head -> data == head -> next -> data){
            Node* toDelete = head -> next;
            head -> next = head -> next -> next;
            delete head -> next;
        }else{
            head = head -> next;
        }
    }
}

void makeCycle(Node* &head, int pos){
    Node* temp = head;
    Node* startCycle;
    int count = 1;
    while(temp -> next != NULL){
        if(count == pos){
            startCycle = temp;
        }
        temp = temp -> next;
        count++;
    }
    temp -> next = startCycle;
}

void detectCycle(Node* head){
    Node* slow = head;
    Node* fast = head;
    while(fast != NULL && fast -> next != NULL){
        slow = slow -> next;
        fast = fast -> next -> next;
        if(slow == fast){
            cout << "Cycle detected!" << endl;
            return;
        }
    }
    cout << "No cycle" << endl;
    return;
}

void cycleCount(Node* head){
    Node* slow = head;
    Node* fast = head;
    int ans = 0;
    while(fast != NULL && fast -> next != NULL){
        slow = slow -> next;
        fast = fast -> next -> next;
        if(slow == fast){
            break;
        }
    }
    if(slow == fast){
        slow = slow -> next;
        ans++;
        while(slow != fast){
            ans++;
            slow = slow -> next;
        }
    }
    cout << ans << "\n";
}

void removeCycle(Node* head){
    Node* slow = head;
    Node* fast = head;
    if(head == NULL && head -> next == NULL){
        return;
    }
    while(fast != NULL && fast -> next != NULL){
        slow = slow -> next;
        fast = fast -> next -> next;
        if(slow == fast){
            break;
        }
    }
    if(slow == fast){
        if(slow == head){
            while(fast -> next != slow){
                fast = fast -> next;
            }
            fast -> next = NULL;
            return;
        }
        fast = head;
        while(fast -> next == slow -> next){
            if(slow -> next == fast){
                slow -> next == NULL;
                return; 
            }
            slow = slow -> next;
            fast = fast -> next;
        }
        slow -> next -> next = NULL;
    }
    return;
}


Node* reverseK(Node* head, int k){
    Node* prevPtr = NULL;
    Node* currPtr = head;
    Node* nextPtr;
    int count = 0;
    while(currPtr != NULL && count < k){
        nextPtr = currPtr -> next;
        currPtr -> next = prevPtr;

        prevPtr = currPtr;
        currPtr = nextPtr;
        count++;
    }
    if(currPtr != NULL){
        head -> next = reverseK(currPtr, k);
    }
    return prevPtr;
}


// Segrigate odd and even nodes in linked list
Node* segrigate(Node* head){
    Node* es = NULL; // even start
    Node* os = NULL; // odd start
    Node* ee = NULL; // even end
    Node* oe = NULL; // odd end
    Node* temp = head; 
    while(temp != NULL){
        int x = temp -> data;
        if(x%2==0){
            if(es == NULL){
                es = temp;
                ee = es;
            }else{
                ee -> next = temp;
                ee = ee -> next;
            }
        }else{
            if(os == NULL){
                os = temp;
                oe = os;
            }else{
                oe -> next = temp;
                oe = oe -> next;
            }
        }
        temp = temp -> next;
    }
    if(os == NULL || es == NULL){
        return head;
    }
    ee -> next = os;
    oe -> next = NULL;
    return es;
}


// Merge Two Sorted Linked List
Node* mergeLL(Node* head1, Node* head2){
    // check corner case
    if(head1 == NULL || head2 == NULL){
        return NULL;
    }
    Node* head = NULL;
    Node* tail = NULL; // tail to change links;
    // make head;
    if(head1 -> data <= head2 -> data){
        head = head1;
        tail = head1;
        head1 = head1 -> next;
    }else{
        head = head2;
        tail = head2;
        head2 = head2 -> next;
    }
    while(head1 != NULL && head2 != NULL){
        if(head1 -> data <= head2 -> data){
            tail -> next = head1;
            tail = tail -> next; // move tail to the next node to which next node will be linked
            head1 = head1 -> next;
        }else{
            tail -> next = head2;
            tail = tail -> next;
            head2 = head2 -> next;
        }
    }
    if(head1 != NULL){
        tail -> next = head1;
        tail = tail -> next;
        head1 = head1 -> next;
    }else{
        tail -> next = head2;
        tail = tail -> next;
        head2 = head2 -> next;
    }
    return head;
}

void printNodes(Node* head){
    for(Node* i = head; i != NULL; i = i -> next){
        cout << i -> data << "->";
    }
    cout << "NULL" << endl;
}

// void printNodes(Node* head){
//     while(head != NULL){
//         cout << head -> data << "->";
//         head = head -> next;
//     }
//     cout << "NULL\n";
//     return;
// }

int main(){
    Node* head = NULL;
    insertAtTail(head, 10);
    insertAtTail(head, 20);
    insertAtTail(head, 30);
    insertAtTail(head, 40);
    insertAtTail(head, 50);
    insertAtTail(head, 60);
    printNodes(head);
    // deleteMidNode(head, 20);
    // printNodes(head);
    // Node* newHead = reverseLL(head);
    // printNodes(newHead);
    // insertAtPosition(head, 4, 45);
    // printNodes(head);
    // Node* newHead = sortedInsert(head, 25);
    // printNodes(head);
    // middleOfLL(head);
    // nFromLast(head, 4);
    // Node* newHead = recursiveReverse(head, NULL);
    // printNodes(newHead);
    // removeDuplicates(head);
    // printNodes(head);
    // Node* newHead = reverseK(head, 2);
    // printNodes(newHead);
    makeCycle(head, 3);
    // printNodes(head);
    detectCycle(head);
    removeCycle(head);
    printNodes(head);
    detectCycle(head);
    return 0;
}