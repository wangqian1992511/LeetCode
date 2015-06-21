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
    void reorderList(ListNode *p) {
        if (!p) return;
        int n = calcLen(p);
        ListNode *q = divideList(p, n);
        q = reverseList(q);
        
        ListNode *t;
        while (q) {
            t = p->next;
            p->next = q;
            p = t;
            t = q->next;
            q->next = p;
            q = t;
        }
    }
private:
    int calcLen(ListNode *head) {
        int ans = 0;
        while (head) {
            head = head->next;
            ans++;
        }           
        return ans;
    }
    ListNode* divideList(ListNode *head, int n) {
        for (int i = 0; i < (n - 1) >> 1; i++)
            head = head->next;
        ListNode *ans = head->next;
        head->next = NULL;
        return ans;
    }
    ListNode* reverseList(ListNode *head) {
        if (!head) return NULL;
        ListNode *tail;
        return _reverseList(head, tail);
    }
    ListNode* _reverseList(ListNode *head, ListNode *&tail) {
        if (!head || !head->next) {
            tail = head;
            return head;
        }
        ListNode *ans = _reverseList(head->next, tail);
        tail->next = head;
        tail = head;
        tail->next = NULL;
        return ans;
    }
};