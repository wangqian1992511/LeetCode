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
    bool hasCycle(ListNode *head) {
        ListNode *f, *s;
        f = head;
        s = head;
        while ((f != NULL) && (s != NULL)) {
            s = s->next;
            if (s == NULL) break;
            f = f->next;
            if (f == NULL) break;
            f = f->next;
            if (f == NULL) break;    
            if (f == s) return true;
        }
        return false;
    }
};