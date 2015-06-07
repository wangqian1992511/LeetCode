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
    int countNodes(TreeNode* root) {
        int ans = 0, hr, hl = calcHeight(root);
        while (root) {
            hl--;
            hr = calcHeight(root->right);
            if (hl != hr) 
                root = root->left;
            else 
                root = root->right; 
            ans += (1 << hr);  
        }
        return ans;
    }
private:
    int calcHeight(TreeNode* root) {
        int ans = 0;
        while (root) {
            ans++;
            root = root->left;
        }
        return ans;
    }
};