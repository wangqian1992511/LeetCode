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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        int n = postorder.size();
        return helper(postorder, 0, n-1, inorder, 0, n-1);
    }
private:
    TreeNode *helper(vector<int> &postorder, int pL, int pR, vector<int> &inorder, int iL, int iR) {
        if (pR < pL) return NULL;
        int val = postorder[pR];
        int p = iL;
        while (inorder[p] != val) p++;
        TreeNode *ans = new TreeNode (val);
        ans->left = helper(postorder, pL, pL+p-iL-1, inorder, iL, p-1);
        ans->right = helper(postorder, pL+p-iL, pR-1, inorder, p+1, iR);
        return ans;
    }
};