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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        ListNode *super = new ListNode(1);
        super->next = head;
        ListNode *p = super, *q = head;
        for (int i = 0; i < m-1; i++) {
            p = q;
            q = q->next;
        }
        ListNode *h, *t, *b;
        build(q, m, n, h, t, b);
        p->next = h;
        t->next = b;
        return super->next;
    }
private:
    void build(ListNode *&q, int m, int n, ListNode *&h, ListNode *&t, ListNode *&b) {
        if (m == n) {
            h = t = q;
            b = q->next;
        }
        else {
            build(q->next, m+1, n, h, t, b);
            t->next = q;
            q->next = b;
            t = q;
        }
    }
};