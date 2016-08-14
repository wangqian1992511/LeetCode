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
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        original = head;
        n = 0;
        while (head) {
            head = head->next;
            n++;
        }
    }

    /** Returns a random node's value. */
    int getRandom() {
        ListNode* head = original;
        int t = rand() % n;
        for (int i = 0; i < t; i++)
            head = head->next;
        return head->val;
    }
private:
    ListNode* original;
    int n;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(head);
 * int param_1 = obj.getRandom();
 */
