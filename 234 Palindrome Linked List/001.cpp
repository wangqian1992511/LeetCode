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
    bool isPalindrome(ListNode* head) {
        int n = calcLen(head);
        ListNode* other = NULL;
        for (int i = 0; i < (n >> 1); i++) {
            ListNode* p = head->next;
            head->next = other;
            other = head;
            head = p;
        }
        if (n & 1)
            head = head->next;
        while (other) {
            if (other->val != head->val)
                return false;
            else {
                other = other->next;
                head = head->next;
            }
        }
        return true;
    }
private:
    int calcLen(ListNode* p) {
        int ans = 0;
        while (p) {
            p = p->next;
            ans++;
        }
        return ans;
    }
};