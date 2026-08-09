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
       ListNode* reverse(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        
        while(curr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        if(!head || !head->next)
        return true;
        int len = 0;
        ListNode* temp = head;
        while(temp) {
            len++;
            temp = temp->next;
        }
        int mid =len/2;
        temp = head;
        for(int i = 0; i < mid; i++)
        {
            temp = temp->next;
        }
        ListNode* righthalf = reverse(temp);
        ListNode* lefthalf = head;
        while(righthalf) {
            if(lefthalf->val!=righthalf->val) 
            {
                return false;
            }
            lefthalf = lefthalf->next;
            righthalf = righthalf->next;
        }
        return true;

    }

};