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
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next) 
        return head;
        ListNode* i=head;
        ListNode* j=head->next;
        ListNode* temp=j;

        while (j!=NULL&&j->next!=NULL) {
            i->next=j->next;
            i=i->next;

            j->next=i->next;
            j=j->next;
        }

        i->next=temp;
        return head;
    }
};