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
    bool isBalanced(TreeNode *root) {
        int h;
        return dfs(root, h);
    }
private:
    bool dfs(TreeNode *root, int &height) {
        if (! root) {
            height = -1;
            return true;
        }
        int lh, rh;
        bool lf = dfs(root->left, lh);
        bool rf = dfs(root->right, rh);
        height = 1 + max(lh, rh);
        return lf && rf && (abs(lh - rh) <= 1);
    }
};