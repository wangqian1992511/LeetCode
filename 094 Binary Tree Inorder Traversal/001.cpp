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
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> ans;
        if (root){
            vector<int> left = inorderTraversal(root->left);
            int ll = left.size();
            for (int i = 0; i < ll; i++)
                ans.push_back(left[i]);            
            ans.push_back(root->val);
            vector<int> right = inorderTraversal(root->right);
            int lr = right.size();
            for (int i = 0; i < lr; i++)
                ans.push_back(right[i]);  
        }
        return ans;
    }
};