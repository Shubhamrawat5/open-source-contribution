#include <iostream>
#include <bits/stdc++.h>
using namespace std;


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* m1 = l1;
    ListNode* m2 = l2;
    ListNode* dummyNode = new ListNode(-1);
    ListNode* mover = dummyNode;
    int carry = 0;
    while(m1 != nullptr || m2 != nullptr) {
        int sum = carry;
        if(m1) sum = sum + m1->val;
        if(m2) sum = sum + m2->val;
        ListNode* newNode = new ListNode(sum % 10);
        carry = sum / 10;
        mover->next = newNode;
        mover = mover->next;
        if(m1) m1 = m1->next;
        if(m2) m2 = m2->next;
    }
    if(carry) {
        ListNode* newNode = new ListNode(carry);
        mover->next = newNode;
    }
    return dummyNode->next;
};

// Function to create linked list from array
ListNode* createList(const vector<int>& nums) {
    ListNode* dummy = new ListNode();
    ListNode* current = dummy;
    for (int num : nums) {
        current->next = new ListNode(num);
        current = current->next;
    }
    return dummy->next;
}

// Functiion to print the linked list
void printList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Create two linked lists
    vector<int> nums1 = {2, 4, 3, 6};
    vector<int> nums2 = {5, 6, 4};

    ListNode* l1 = createList(nums1);
    ListNode* l2 = createList(nums2);

    // Print the input lists
    cout << "Input List 1: ";
    printList(l1);
    cout << "Input List 2: ";
    printList(l2);

    // Add the two numbers
    ListNode* result = addTwoNumbers(l1, l2);

    // Print the result
    cout << "Result: ";
    printList(result);

    // Clean the memory
    delete l1;
    delete l2;
    delete result;

    return 0;
}
