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
    ListNode *sortList(ListNode *head) {
        if (!head || !head->next) return head;
        int n = getLen(head);
        
        ListNode *mid = head, *tmp;
        for (int i = 1; i < n/2; i++)
            mid = mid->next;
        tmp = mid->next;
        mid->next = NULL;
        mid = tmp;
        
        ListNode *ansH = new ListNode(0);
        ListNode *ansT = ansH;
        ListNode *a = sortList(head);
        ListNode *b = sortList(mid);
        while (a && b) {
            if (a->val < b->val) {
                ansT->next = a;
                ansT = a;
                a = a->next;
            }
            else {
                ansT->next = b;
                ansT = b;
                b = b->next;
            }
        }
        if (a)
            ansT->next = a;
        else
            ansT->next = b;
        return ansH->next;
    }
private:
    int getLen(ListNode *head) {
        int ans = 0;
        while (head) {
            ans++;
            head = head->next;
        }
        return ans;
    }  
};