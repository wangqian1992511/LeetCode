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
    int maxPathSum(TreeNode *root) {
        int ans, tmp;
        calc(root, ans, tmp);
        return ans;
    }
private:
    void calc(TreeNode * root, int &vRoot, int &vEnd) {
        vEnd = root->val;
        vRoot = root->val;
        
        int lRoot, lEnd;
        if (root->left) {
            calc(root->left, lRoot, lEnd);
            if (lEnd + root->val > vEnd)
                vEnd = lEnd + root->val;
            if (lRoot > vRoot)
                vRoot = lRoot;
        }
        
        int rRoot, rEnd;
        if (root->right) {
            calc(root->right, rRoot, rEnd);
            if (rEnd + root->val > vEnd)
                vEnd = rEnd + root->val;
            if (rRoot > vRoot)
                vRoot = rRoot;
        }
        
        if (vEnd > vRoot)
            vRoot = vEnd;
        if (root->right && root->left && lEnd+rEnd+root->val > vRoot)
            vRoot = lEnd+rEnd+root->val;
    }
};