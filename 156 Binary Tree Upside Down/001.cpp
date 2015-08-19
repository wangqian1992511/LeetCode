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
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        TreeNode* lastRight = NULL;
        thisQ = false;
        if (root) q[thisQ].push(root);
        
        while (!q[thisQ].empty()) {
            thisQ = !thisQ;
            
            TreeNode* u = popFront();
            u->right = lastRight;
            lastRight = u;
            
            while (!q[!thisQ].empty()) {
                TreeNode* v = popFront();
                v->right = NULL;
                u->left = v;
                u = v;
            }
            
            u->left = NULL;
        }
        
        return lastRight;
    }

private:
    queue<TreeNode*> q[2];
    bool thisQ;
    TreeNode* popFront() {
        TreeNode* u = q[!thisQ].front();
        q[!thisQ].pop();
        if (u->left) q[thisQ].push(u->left);
        if (u->right) q[thisQ].push(u->right);
        return u;
    }
};