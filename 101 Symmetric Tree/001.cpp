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
    bool isSymmetric(TreeNode *root) {
        if (root)
            return isEqu(root->left, root->right);
        return true;
    }
private:
    bool isEqu(TreeNode *left, TreeNode *right) {
        if (!left && !right)
            return true;
        else if (left && !right)
            return false;
        else if (right && !left)
            return false;
        else if (left->val != right->val)
            return false;
        else 
            return isEqu(left->right, right->left) && isEqu(left->left, right->right);
    }
};