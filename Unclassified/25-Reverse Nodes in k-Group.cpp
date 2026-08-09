
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head==NULL||k==1) 
        return head;

        ListNode* dummy=new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;
        ListNode* curr = head;
        int count = 0;
        while (curr!=NULL) {
            count++;
            curr = curr->next;
        }
        while (count >= k) 
        {
            curr = prev->next;
            ListNode* nxtNode = curr->next;

            for (int i = 1; i < k; i++) {
                curr->next = nxtNode->next;
                nxtNode->next = prev->next;
                prev->next = nxtNode;
                nxtNode = curr->next;
            }
            prev = curr;
            count -= k;
        }

        return dummy->next;
    }
};