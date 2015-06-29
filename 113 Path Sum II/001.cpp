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
    vector<vector<int>> pathSum(TreeNode *root, int sum) {
        if (root)
            dfs(root, sum);
        return ans;
    }
private:
    vector<vector<int>> ans;
    vector<int> tmp;
    void dfs(TreeNode *root, int rmn) {
        tmp.push_back(root->val);
        rmn -= root->val;
        if (!rmn && !root->left && !root->right)
            ans.push_back(tmp);
        if (root->left)
            dfs(root->left, rmn);
        if (root->right)
            dfs(root->right, rmn);
        rmn += root->val;
        tmp.pop_back();
    }
};