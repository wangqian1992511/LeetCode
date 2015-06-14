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
    ListNode *detectCycle(ListNode *head) {
        ListNode *p = head, *q = head;
        while (p && q) {
            if (!p) return NULL;
            p = p->next;
            if (!q) return NULL;
            q = q->next;
            if (!q) return NULL;
            q = q->next;
            if (p == q) {
                do {
                    q = p;
                    p = p->next;
                    q->next = NULL;
                } while (p);
                while (head->next)
                    head = head->next;
                return head;
            }
        }
        return NULL;
    }
};