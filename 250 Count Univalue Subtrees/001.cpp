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
    int countUnivalSubtrees(TreeNode* root) {
        ans = 0;
        int tmp;
        if (root)
            count(root, tmp);
        return ans;
    }
private:
    int ans;
    bool count(TreeNode* root, int &val) {
        val = root->val;
        int a = val, b = val;
        bool fa = true, fb = true;
        if (root->left) 
            fa = count(root->left, a);
        if (root->right)
            fb = count(root->right, b);
        bool flag = (val == a) && (val == b) && fa && fb;
        ans += flag;
        return flag;
    }
};