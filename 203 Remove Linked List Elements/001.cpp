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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *super = new ListNode(0);
        super->next = head;
        ListNode *p = super;
        while (p->next) {
            if (p->next->val == val) 
                p->next = p->next->next;
            else
                p = p->next;
        }
        return super->next;
    }
};