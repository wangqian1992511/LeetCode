/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        vector<TreeLinkNode*> cand;
        dfs(root, 0, cand);
        int n = cand.size();
        for (int i = 0; i < n; i++)
            cand[i]->next = NULL;
    }
private:
    void dfs(TreeLinkNode* root, int d, vector<TreeLinkNode*> &cand) {
        if (!root) return;
        if (d >= cand.size())
            cand.push_back(root);
        else {
            cand[d]->next = root;
            cand[d] = root;
        }
        dfs(root->left, d + 1, cand);
        dfs(root->right, d + 1, cand);
    } 
};