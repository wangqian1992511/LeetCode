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
    ListNode *insertionSortList(ListNode *head) {
        ListNode *super = new ListNode (0);
        super->next = head;
        ListNode *tail = super; 
        ListNode *p, *q;
        while (tail->next) {
            q = super;
            p = tail->next;
            while ((q->next->val < p->val) && (q != tail)) 
                q = q->next;
            if (q != tail) {
                tail->next = p->next;
                p->next = q->next;
                q->next = p;
            }
            else
                tail = p;
        }
        return super->next;
    }
};