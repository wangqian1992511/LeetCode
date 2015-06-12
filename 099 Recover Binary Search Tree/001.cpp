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
    void recoverTree(TreeNode* root) {
        minV = INT_MAX;
        maxV = INT_MIN;
        haveWrong = false;
        dfs(root);
        if (minN) swap(minN->val, maxN->val);
    }
private:
    TreeNode *maxN, *minN;
    int minV, maxV;
    bool haveWrong;
    void dfs(TreeNode* root) {
        if (!root) return;
        dfs(root->left);
        if (!haveWrong && (root->val > maxV)) {
            maxV = root->val;
            maxN = root;
        }
        else if (!haveWrong && (root->val < maxV)) {
            haveWrong = true;
            minV = root->val;
            minN = root;
        }
        else if (haveWrong && (root->val < minV)) {
            minV = root->val;
            minN = root;
        }
        dfs(root->right);
    }
};