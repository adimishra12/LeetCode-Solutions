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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == nullptr)
            return 0;

        ListNode* nxt = head -> next;
        ListNode* prev = head;

        while(nxt)
        {
            if(prev -> val == nxt -> val)
            {
                prev -> next = nxt -> next;
                nxt = prev -> next;
            }
            else
            {
                prev = nxt;
                nxt = nxt -> next;
            }
        }
        return head;
    }
};