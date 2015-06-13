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
        ListNode* tail = new ListNode(0);
        return helper(head, tail);
    }
private:
    ListNode* helper(ListNode* head, ListNode* &tail) {
        if (!head || !head->next) {
            tail = head;
            return head;
        }
        ListNode *ans = helper(head->next, tail);
        tail->next = head;
        tail = head;
        tail->next = NULL;
        return ans;
    }
};
