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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if (n == 0)
            return NULL;
        if (n == 1)
            return lists[0];

        vector<ListNode*> newLists;
        if (n & 1) {
            newLists.push_back(lists[n - 1]);
            n--;
        }

        for (int i = 0; i < n; i += 2)
            newLists.push_back(mergeTwoLists(lists[i], lists[i + 1]));
        return mergeKLists(newLists);
    }
private:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode *h = new ListNode(0);
        ListNode *t = h;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                t->next = l1;
                t = t->next;
                l1 = l1->next;
            }
            else {
                t->next = l2;
                t = t->next;
                l2 = l2->next;
            }
        }
        if (l1)
            t->next = l1;
        else
            t->next = l2;
        return h->next;
    }
};
