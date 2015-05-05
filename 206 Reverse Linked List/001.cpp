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
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* ans = reverseList(head->next);
        head->next = NULL;
        ListNode *p = ans;
        while (p->next)
            p = p->next;
        p->next = head;
        return ans;
    }
};