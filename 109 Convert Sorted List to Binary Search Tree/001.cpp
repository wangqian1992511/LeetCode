/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode *sortedListToBST(ListNode *head) {
        int n = getLen(head);
        TreeNode *ans = dfs(head, n);
        return ans;
    }
private:
    int getLen(ListNode *head) {
        int n = 0;
        while (head) {
            head = head->next;
            n++;
        }
        return n;
    }
    TreeNode* dfs(ListNode *&head, int n) {
        if (!n) return NULL;
        TreeNode *ans = new TreeNode(0);
        ans->left = dfs(head, n/2);
        ans->val = head->val;
        head = head->next;
        ans->right = dfs(head, n - n/2 - 1);
        return ans;
    }    
};