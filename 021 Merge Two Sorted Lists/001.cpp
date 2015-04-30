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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode *h = new ListNode(0);
        ListNode *t = h;
        while (l1 && l2) {
            if (l1->val <= l2->val) {
                t->next = l1;
                t = t->next;
                l1 = l1->next;
            }
            else {
                t->next = l2;
                t = t->next;
                l2 = l2->next;
            }
        }
        if (l1)
            t->next = l1;
        else
            t->next = l2;
        return h->next;
    }
};