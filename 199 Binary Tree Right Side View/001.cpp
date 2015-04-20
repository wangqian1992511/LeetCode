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
    vector<int> rightSideView(TreeNode *root) {
        vector<int> ans;
        dfs(root, 0, ans);
        return ans;
    }
private:
    bool dfs(TreeNode *root, int dep, vector<int> &ans) {
        if (root) {
            if (ans.size() > dep) 
                ans[dep] = root->val;
            else 
                ans.push_back(root->val);
            dfs(root->left, dep+1, ans);
            dfs(root->right, dep+1, ans);
        }
    }
};