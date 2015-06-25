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
    ListNode *partition(ListNode *head, int x) {
        if (!head) return NULL;
        ListNode *la = new ListNode (0);
        ListNode *lb = new ListNode (0);
        ListNode *ta = la, *tb = lb;
        while (head) {
            if (head->val < x)
                link(head, ta);
            else
                link(head,tb);
        }
        ta->next = lb->next;
        return la->next;
    }
private:
    void link(ListNode *&head, ListNode *&t) {
        t->next = head;
        t = head;
        head = head->next;
        t->next = NULL;
    }
};