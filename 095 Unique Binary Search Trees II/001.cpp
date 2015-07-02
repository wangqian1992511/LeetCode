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
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> ans = build(1, n);
        return ans;
    }
private:
    vector<TreeNode*> build(int st, int en) {
        vector<TreeNode*> ans;
        if (st > en) 
            ans.push_back(NULL);
        else
            for (int i = st; i <= en; i++) {
                vector<TreeNode*> left = build(st, i-1);
                vector<TreeNode*> right = build(i+1,en);
                int lN = left.size(), rN = right.size();
                for (int j = 0; j < lN; j++)
                    for (int k = 0; k < rN; k++) {
                        TreeNode* root = new TreeNode(i);
                        root->left = left[j];
                        root->right = right[k];
                        ans.push_back(root);
                    }
            }
        return ans;
    }
};