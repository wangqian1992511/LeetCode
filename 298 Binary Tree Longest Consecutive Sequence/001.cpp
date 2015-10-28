/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
struct statT {  
    TreeNode* root;
    int len;
};
 
class Solution {
public:
    int longestConsecutive(TreeNode* root) {
        int ans = 0;
        queue<statT> q;
        statT t = {root, 1};
        if (root) q.push(t);
        while (!q.empty()) {
            statT head = q.front();
            q.pop();
            ans = max(ans, head.len);
            statT t;
            if (head.root->left) {
                t.root = head.root->left;
                t.len = (head.root->val + 1 == head.root->left->val) ? (head.len + 1) : 1;
                q.push(t);
            }
            if (head.root->right) {
                t.root = head.root->right;
                t.len = (head.root->val + 1 == head.root->right->val) ? (head.len + 1) : 1;
                q.push(t);
            }
        }
        return ans;
    }
};
