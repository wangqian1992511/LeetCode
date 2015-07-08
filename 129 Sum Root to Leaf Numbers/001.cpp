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
    int sumNumbers(TreeNode *root) {
        if (!root) return 0;
        return getSum(root, 0);
    }
private:
    int getSum(TreeNode *root, int now) {
        int t = now * 10 + root->val;
        if (!root->left && !root->right) {
            return t;
        }
        else if (root->left && root->right) {
            return getSum(root->left, t) + getSum(root->right, t);
        }
        else if (root->left)
            return getSum(root->left, t);
        else
            return getSum(root->right, t);
    }
};