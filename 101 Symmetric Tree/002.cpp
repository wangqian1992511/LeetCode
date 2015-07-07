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
        if (!root) return true;
        queue<TreeNode*> qa, qb;
        qa.push(root->left);
        qb.push(root->right);
        
        while (!qa.empty()) {
            TreeNode *x = qa.front();
            TreeNode *y = qb.front();
            qa.pop();
            qb.pop();
            
            if (!x && !y) continue;
            if (!x || !y) return false;    
            if (x->val != y->val) return false;
            
            qa.push(x->left);
            qb.push(y->right);
            qa.push(y->left);
            qb.push(x->right);
        }
        return true;
    }
};