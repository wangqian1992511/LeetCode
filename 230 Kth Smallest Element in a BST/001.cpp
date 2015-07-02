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
    int kthSmallest(TreeNode* root, int k) {
        find(root, k);
        return ans;
    }
private:
    int ans;
    bool find(TreeNode* root, int &k) {
        if (!root)
            return false;
        if (find(root->left, k))
            return true;
        k--;
        if (!k) {
            ans = root->val;
            return true;
        }
        if (find(root->right, k))
            return true;
        return false;
    }
};