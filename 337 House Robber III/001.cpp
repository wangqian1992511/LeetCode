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
    int rob(TreeNode* root) {
        int yes, no;
        dfs(root, yes, no);
        return max(yes, no);
    }
private:
    void dfs(TreeNode* root, int &yesMax, int &noMax) {
        yesMax = 0;
        noMax = 0;
        if (root) {
            int leftY, leftN, rightY, rightN;
            dfs(root->left, leftY, leftN);
            dfs(root->right, rightY, rightN);
            yesMax = root->val + leftN + rightN;
            noMax = max(leftN, leftY) + max(rightY, rightN);
        }
    }
};