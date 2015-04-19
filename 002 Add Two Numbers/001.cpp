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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *ans = new ListNode(0);
        ListNode *t = ans;
        int c = 0;
        while (l1 && l2) {
            int a = l1->val;
            int b = l2->val;
            
            ListNode *p = new ListNode((a + b + c) % 10);
            t->next = p;
            t = p;
            
            c = (a + b + c) / 10;
            l1 = l1->next;
            l2 = l2->next;
        }
        while (l1) {
            int a = l1->val;
            
            ListNode *p = new ListNode((a + c) % 10);
            t->next = p;
            t = p;
            
            c = (a + c) / 10;
            l1 = l1->next;
        }
        while (l2) {
            int a = l2->val;
            
            ListNode *p = new ListNode((a + c) % 10);
            t->next = p;
            t = p;
            
            c = (a + c) / 10;
            l2 = l2->next;
        }        
        if (c > 0) {
            ListNode *p = new ListNode(c);
            t->next = p;
            t = p; 
        }
        return ans->next;
    }
};