/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct comp {
    bool operator () (ListNode* a, ListNode* b) {
        return a->val > b->val;
    }  
};
class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        int n = lists.size();
        priority_queue<ListNode*, vector<ListNode*>, comp> heap;
        for (int i = 0; i < n; i++)
            if (lists[i])
                heap.push(lists[i]);
            
        ListNode *super, *tail;
        super = new ListNode(0);
        tail = super;
        while (!heap.empty()) {
            ListNode *p = heap.top();
            heap.pop();
            ListNode *q = new ListNode(p->val);
            p = p->next;
            tail->next = q;
            tail = q;
            if (p)
                heap.push(p);
        }
        
        return super->next;
    }
};