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
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if (p->right) {
            p = p->right;
            while (p->left)
                p = p->left;
            return p;
        } else if (p->val == root->val) {
            return NULL;
        } else if (p->val > root->val) {
            return inorderSuccessor(root->right, p);
        } else {
            TreeNode* ans = inorderSuccessor(root->left, p);
            return ans ? ans : root;
        }
        return NULL;
    }
};
