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
    bool isValidBST(TreeNode *root) {
        int64_t a, b;
        return isValid(root, a, b);
    }
private:
    bool isValid(TreeNode *root, int64_t &maxV, int64_t &minV) {
        if (!root) {
            maxV = INT64_MIN;
            minV = INT64_MAX;
            return true;
        }
        int64_t lmin, lmax, rmin, rmax;
        if (!isValid(root->left, lmax, lmin)) return false;
        if (!isValid(root->right, rmax, rmin)) return false;
        maxV = root->right ? rmax : root->val; 
        minV = root->left ? lmin : root->val;
        return (lmax < root->val) && (root->val < rmin);
    }
};