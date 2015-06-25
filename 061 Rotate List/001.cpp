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
    ListNode *rotateRight(ListNode *head, int k) {
        if (!head) return NULL;
        int n = 1;
        ListNode *tail = head;
        while (tail->next) {
            tail = tail->next;
            n++;
        }
        k = k % n;
        if (!k) return head;
        ListNode *p = head;
        for (int i = 0; i < n - k - 1; i++)
            p = p->next;
        ListNode *ans = p->next;
        tail->next = head;
        p->next = NULL;
        return ans;
    }
};