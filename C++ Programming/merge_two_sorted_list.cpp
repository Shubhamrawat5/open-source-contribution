#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(NULL) {}
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode* head = new ListNode();
    ListNode* temp = head;
    while(list1 && list2) {
        if(list1->val < list2->val) {
            temp->next = list1;
            list1 = list1->next;
        }
        else {
            temp->next = list2;
            list2 = list2->next;
        }
        temp = temp->next;
    }
    if(list1) temp->next = list1;
    if(list2) temp->next = list2;
    return head->next;
}

void printList(ListNode* node) {
    while (node) {
        cout << node->val;
        if (node->next) cout << " -> ";
        node = node->next;
    }
    cout << endl;
}

ListNode* createList(const vector<int>& arr) {
    if (arr.empty()) return NULL;
    ListNode* head = new ListNode(arr[0]);
    ListNode* current = head;
    for (size_t i = 1; i < arr.size(); ++i) {
        current->next = new ListNode(arr[i]);
        current = current->next;
    }
    return head;
}

int main() {
    vector<int> list1_vals = {12, 62, 84};
    vector<int> list2_vals = {1, 37, 49, 53, 78};

    ListNode* list1 = createList(list1_vals);
    ListNode* list2 = createList(list2_vals);

    ListNode* mergedList = mergeTwoLists(list1, list2);

    cout << "Merged list: ";
    printList(mergedList);

    while (mergedList) {
        ListNode* temp = mergedList;
        mergedList = mergedList->next;
        delete temp;
    }
    return 0;
}
