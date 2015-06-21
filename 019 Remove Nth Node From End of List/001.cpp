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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *super = new ListNode(0);
        super->next = head;
        ListNode *tail = super;
        head = super;
        for (int i = 0; i < n; i++)
            tail = tail->next;
        while (tail->next) {
            tail = tail->next;
            head = head->next;
        }
        head->next = head->next->next;
        return super->next;
    }
};