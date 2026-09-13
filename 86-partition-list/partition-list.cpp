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
    ListNode* partition(ListNode* head, int x) {
        ListNode* curr = head;
        ListNode* less = new ListNode(0); // < x ke liye
        ListNode* lessptr = less;

        ListNode* greaterEqual = new ListNode(0); // >= x
        ListNode* greatptr = greaterEqual;

        while(curr != nullptr)
        {
            if(curr -> val < x)
            {    // attaching curr node to less ll
                lessptr -> next = new ListNode(curr -> val);
                lessptr = lessptr -> next; // ptr badha do
            }
            else
            {
                // attaching curr node to greaterEqual ll
                greatptr -> next = new ListNode(curr -> val);
                greatptr = greatptr -> next; // ptr badha do
            }
            curr = curr -> next; // increment kro dusri node pe jao
        }
        lessptr -> next = greaterEqual -> next; // greater wali ll ko less wali ke end pe laga do

        return less -> next; // modified ll return kro pehli node se less wali dummy node ke baad
    }
};