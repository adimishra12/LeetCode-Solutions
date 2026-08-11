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
    void reorderList(ListNode* head) {
        if(head == nullptr || head -> next == nullptr || head -> next -> next == nullptr)
            return;
        ListNode* dummy = head;
        while(dummy -> next -> next)
            dummy = dummy -> next;
        dummy->next->next = head -> next;
        head -> next = dummy -> next;

        dummy -> next = nullptr;

        reorderList(head -> next -> next);        
    }
};