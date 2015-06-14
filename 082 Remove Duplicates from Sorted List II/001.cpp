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
    ListNode *deleteDuplicates(ListNode *head) {
        if (!head) return head;
        ListNode *super = new ListNode(INT_MAX);
        super->next = head;
        ListNode *p = super, *q = head, *r = head->next;
        while (q && r) {
            while (r && (q->val != r->val)) {
                p = q;
                q = r; 
                r = r->next;
            }
            if (r) {
                int now = r->val;
                while (p->next && (q->val == now)) {
                    p->next = q->next;
                    q = p->next;
                }
            }
            if (q) r = q->next;
        }
        return super->next;
    }
};