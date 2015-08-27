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
    int closestValue(TreeNode* root, double target) {
        if (abs(target - root->val) < 1e-10)
            return root->val;
        else if (target > root->val) {
            int x = root->right ? closestValue(root->right, target) : root->val;
            return abs(x - target) < abs(root->val - target) ? x : root->val;
        }
        else if (target < root->val) {
            int x = root->left ? closestValue(root->left, target) : root->val;
            return abs(x - target) < abs(root->val - target) ? x : root->val;
        }
    }
};