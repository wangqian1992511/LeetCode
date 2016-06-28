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
    ListNode* plusOne(ListNode* head) {
        ListNode *q = new ListNode (0), *p;
        q->next = head;
        head = q;

        while (q) {
            p = q;
            while (p->next && (p->next->val != 9))
                p = p->next;
            q = p->next;
            while (q && (q->val == 9))
                q = q->next;
        }

        p->val++;
        p = p->next;
        while (p) {
            p->val = 0;
            p = p->next;
        }

        if (head->val)
            return head;
        return head->next;
    }
};
