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
    ListNode *swapPairs(ListNode *head) {
        if ((!head) || (! (head->next)))
            return head;
        ListNode* p = head->next;
        ListNode* t = swapPairs(p->next);
        p->next = head;
        head->next = t;
        return p;
    }
};