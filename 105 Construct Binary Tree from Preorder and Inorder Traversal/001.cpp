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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        int n = preorder.size();
        return helper(preorder, 0, n-1, inorder, 0, n-1);
    }
private:
    TreeNode* helper(vector<int> &preorder, int pL, int pR, vector<int> &inorder, int iL, int iR) {
        if (pR < pL) return NULL;
        int val = preorder[pL];
        int p = iL;
        while (inorder[p] != val) p++;
        TreeNode *ans = new TreeNode (val);
        ans->left = helper(preorder, pL+1, pL+p-iL, inorder, iL, p-1);
        ans->right = helper(preorder, pL+p-iL+1, pR, inorder, p+1, iR);
        return ans;
    }
};