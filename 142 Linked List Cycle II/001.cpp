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
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast = head, *slow = head;
        do {
            if (fast)
                fast = fast->next;
            if (fast)
                fast = fast->next;
            if (slow)
                slow = slow->next;
        } while (slow && fast != slow);

        if (slow) {
            fast = head;
            while (fast != slow) {
                fast = fast->next;
                slow = slow->next;
            }
        }

        return slow;
    }
};
