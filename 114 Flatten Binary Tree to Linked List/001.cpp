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
    void flatten(TreeNode *root) {
        TreeNode *st, *en;
        preorder(root, st, en);
    }
private:
    void preorder(TreeNode *root, TreeNode *&st, TreeNode *&en) {
        if (!root) {
            st = NULL;
            en = NULL;
            return;
        }
        
        TreeNode *lSt, *lEn;
        preorder(root->left, lSt, lEn);
        TreeNode *rSt, *rEn;
        preorder(root->right, rSt, rEn);
        
        root->left = NULL;
        root->right = lSt;
        if (lEn)
            lEn->right = rSt;
        else
            root->right = rSt;
        
        st = root;    
        if (rEn)
            en = rEn;
        else if (lEn)
            en = lEn;
        else 
            en = root;
    }
};