/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k==1) return head;
      ListNode dummy;
        ListNode *d_head = &dummy, *d_tail = &dummy;
        ListNode *head_copy = head;
        int n=0;
        while(head_copy)
        {
            head_copy = head_copy->next;
            n++;
        }
        int x = n/k;
        head_copy = head;
        int i=0,j=0;
        while(head_copy)
        {
            i++;
            if(i%k != 1)
            {
              ListNode* temp=head_copy->next;
                head_copy->next = d_head->next;
                d_head->next = head_copy;
                head_copy = temp;
            }
            else
            {
              ListNode* temp = head_copy->next;
                d_head = d_tail;
                d_head->next = head_copy;
                d_tail = head_copy;
                head_copy=temp;
                j++;
            }
            if(j==x+1) break;
        }
        d_tail->next = head_copy;
        return dummy.next;
    }
};