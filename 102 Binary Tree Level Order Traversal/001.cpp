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
    vector<vector<int>> levelOrder(TreeNode *root) {
        vector<vector<int>> ans;
        vector<int> value;
        vector<TreeNode*> pre, now;
        if (root) {
            now.push_back(root);
            value.push_back(root->val);
        }
        while (! now.empty()) {
            ans.push_back(value);
            value.clear();
            pre = now;
            now.clear();
            int n = pre.size();
            for (int i = 0 ; i < n; i++) {
                if (pre[i]->left) {
                    now.push_back(pre[i]->left);
                    value.push_back(pre[i]->left->val);
                }
                if (pre[i]->right) {
                    now.push_back(pre[i]->right);
                    value.push_back(pre[i]->right->val);
                }
            }
        }
        return ans;
    }
};