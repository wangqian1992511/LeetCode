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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        stack<TreeNode*> ps, qs;
        isFind = false;
        dfs(root, p, ps);
        isFind = false;
        dfs(root, q, qs);
        unordered_set<TreeNode*> s;
        while (!ps.empty()) {
            s.emplace(ps.top());
            ps.pop();
        }
        while (!qs.empty()) {
            if (s.find(qs.top()) != s.end())
                return qs.top();
            qs.pop();
        }
        return NULL;
    }
private:
    bool isFind;
    void dfs(TreeNode* root, TreeNode* p, stack<TreeNode*> &ps) {
        if (!root) return;
        ps.push(root);
        if (root == p) isFind = true;
        if (!isFind) dfs(root->left, p, ps);
        if (!isFind) dfs(root->right, p, ps);
        if (!isFind) ps.pop();
    }
};