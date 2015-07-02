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
    TreeNode *sortedArrayToBST(vector<int> &num) {
        int n = num.size();
        int l = 0, r = n - 1;
        TreeNode *ans = doit(num, l, r);
        return ans;
    }
private:
    TreeNode* doit(vector<int> &num, int l, int r) {
        if (l > r) return NULL;
        int m = (l + r) >> 1;
        TreeNode *ans = new TreeNode(num[m]);
        ans->left = doit(num, l, m - 1);
        ans->right = doit(num, m + 1, r);
        return ans;
    }
};