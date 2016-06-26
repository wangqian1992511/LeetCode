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
    vector<vector<int>> findLeaves(TreeNode* root) {
        dfs(root);
        return ans;
    }
private:
    vector<vector<int>> ans;
    int dfs(TreeNode* root) {
        if (!root) return 0;

        int leftV = dfs(root->left);
        int rightV = dfs(root->right);
        int thisV = max(leftV, rightV);

        if (ans.size() == thisV)
            ans.push_back(vector<int> ());
        ans[thisV].push_back(root->val);
        return thisV + 1;
    }
};
