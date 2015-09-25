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
        }
        return helper(root, p);
    }
private:
    TreeNode* helper(TreeNode* root, TreeNode* noRight) {
        if (noRight->val > root->val)
            helper(root->right, noRight);
        else if (noRight->val == root->val)
            return NULL;
        else {
            TreeNode* ans = helper(root->left, noRight);
            if (ans)
                return ans;
            return root;
        }
    }
};
