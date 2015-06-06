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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int la = getLen(headA);
        int lb = getLen(headB);
        
        if (la > lb)
            for (int i = 0; i < (la - lb); i++)
                headA = headA->next;
        
        if (lb > la)
            for (int i = 0; i < (lb - la); i++)
                headB = headB->next;
        
        while (headA != headB) {
           headA = headA->next;
           headB = headB->next;
        }
        
        return headA;
    }
private:
    int getLen(ListNode *head) {
        int ans = 0;
        while (head) {
            head = head->next;
            ans++;
        }
        return ans;
    }
};