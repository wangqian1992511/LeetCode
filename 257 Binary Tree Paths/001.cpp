/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        if (root) 
            dfs(root, to_string(root->val));
        return ans;
    }
private:
    vector<string> ans;
    void dfs(TreeNode* root, string s) {
        if (!root->left && !root->right)
            ans.push_back(s);
        if (root->left)
            dfs(root->left, s + "->" + to_string(root->left->val));
        if (root->right)
            dfs(root->right, s + "->" + to_string(root->right->val));
    }
};