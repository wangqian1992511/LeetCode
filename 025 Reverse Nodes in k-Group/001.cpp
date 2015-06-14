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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head) return NULL;
        if (k == 1) return head;
        
        int n = 0;
        ListNode *h = head;
        while (h) {
            n++;
            h = h->next;
        }
        int m = n / k;
        if (!m) return head;
        
        ListNode *super = new ListNode (0);
        super->next = head;
        ListNode *p = head, *q, *t = super;
        for (int j = 0; j < m; j++) {
            q = p->next;
            for (int i = 1; i < k; i++) {
                p->next = q->next;
                q->next = t->next;
                t->next = q;
                q = p->next;
            }
            t = p;
            p = q;
        }
        return super->next;
    }
};