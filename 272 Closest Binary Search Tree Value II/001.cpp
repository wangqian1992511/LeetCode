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
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        if (!k) return ans;
        findClosest(root, target);
        while (ans.size() != k) {
            if (big.empty()) {
                TreeNode* smallNode = small.top();
                small.pop();
                ans.push_back(smallNode->val);
                addSmall(smallNode->left);
            }
            else if (small.empty()) {
                TreeNode* bigNode = big.top();
                big.pop();
                ans.push_back(bigNode->val);
                addBig(bigNode->right);
            }
            else {
                TreeNode* smallNode = small.top();
                TreeNode* bigNode = big.top();
                if (target - smallNode->val < bigNode->val - target) {
                    small.pop();
                    ans.push_back(smallNode->val);
                    addSmall(smallNode->left);
                }
                else {
                    big.pop();
                    ans.push_back(bigNode->val);
                    addBig(bigNode->right);
                }
            }
        }
        return ans;
    }
private:
    stack<TreeNode*> small, big;
    vector<int> ans;
    void addBig(TreeNode* root) {
        while (root) {
            big.push(root);
            root = root->left;
        }
    }
    void addSmall(TreeNode* root) {
        while (root) {
            small.push(root);
            root = root->right;
        }
    }
    void findClosest(TreeNode* root, double target) {
        if (abs(target - root->val) < 1e-10) {
            addBig(root->right);
            addSmall(root->left);
            ans.push_back(root->val);
        }
        else if (target < root->val) {
            big.push(root);
            if (root->left) 
                findClosest(root->left, target);
        }
        else {
            small.push(root);
            if (root->right) 
                findClosest(root->right, target);
        }
    }
};
