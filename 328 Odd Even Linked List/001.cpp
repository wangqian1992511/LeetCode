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
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next || !head->next->next)
            return head;
        ListNode *odd = head, *even = head->next;
        ListNode *half = even;
        while (even && even->next) {
            odd = odd->next = even->next;
            even = even->next = odd->next;
        }
        odd->next = half;
        return head;
    }
};
