/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* i= headA;
        ListNode* j= headB;
        while(i!=j)
        {   
            if(i==NULL)
            i=headB;
            else
            i=i->next;
            if(j==NULL)
            j=headA;
            else
            j=j->next;
        }
        return i;
    }
};