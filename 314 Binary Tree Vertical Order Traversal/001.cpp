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
    vector<vector<int>> verticalOrder(TreeNode* root) {
        queue<TreeNode*> q;
        queue<int> d;
        
        if (root) {
            q.push(root);
            d.push(0);
        }
        
        unordered_map<int, vector<int>> hash;
        int minDep = 1, maxDep = -1;
        
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            int dep = d.front();
            d.pop();
            
            minDep = min(minDep, dep);
            maxDep = max(maxDep, dep);
            
            hash[dep].push_back(node->val);
            if (node->left) {
                q.push(node->left);
                d.push(dep - 1);
            }
            if (node->right) {
                q.push(node->right);
                d.push(dep + 1);
            }
        }
        
        vector<vector<int>> ans;
        for (int i = minDep; i <= maxDep; i++)
            ans.push_back(hash[i]);
        return ans;
    }
};