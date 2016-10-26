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
    vector<vector<int>> levelOrderBottom(TreeNode *root) {
        vector<vector<int>> ans;

        if (root) {
            vector<TreeNode*> thisLevelNodes(1, root);
            vector<int> vals(1, root->val);

            while (!thisLevelNodes.empty()) {
                ans.push_back(vals);
                vals.clear();
                vector<TreeNode*> nextLevelNodes;
                for (auto it: thisLevelNodes) {
                    if (it->left) {
                        nextLevelNodes.push_back(it->left);
                        vals.push_back(it->left->val);
                    }
                    if (it->right) {
                        nextLevelNodes.push_back(it->right);
                        vals.push_back(it->right->val);
                    }
                }
                thisLevelNodes = nextLevelNodes;
            }
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};
