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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;

        if (root) {
            vector<TreeNode*> thisLevelNodes(1, root);
            vector<int> vals(1, root->val);
            bool reverseLevel = false;

            while (!thisLevelNodes.empty()) {
                if (reverseLevel)
                    reverse(vals.begin(), vals.end());
                reverseLevel = !reverseLevel;
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

        return ans;
    }
};
