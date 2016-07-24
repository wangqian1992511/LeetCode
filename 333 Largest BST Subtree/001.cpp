/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
struct ansT {
    bool isValid;
    int size, minV, maxV;
};

class Solution {
public:
    int largestBSTSubtree(TreeNode* root) {
        return helper(root).size;
    }
private:
    ansT helper(TreeNode* root) {
        ansT ansThis;
        if (!root) {
            ansThis.isValid = true;
            ansThis.size = 0;
            return ansThis;
        }

        ansT ansLeft = helper(root->left);
        ansT ansRight = helper(root->right);

        if (isValid(ansLeft, ansRight, root)) {
            ansThis.isValid = true;
            ansThis.size = ansLeft.size + 1 + ansRight.size;
            ansThis.minV = root->left ? ansLeft.minV : root->val;
            ansThis.maxV = root->right ? ansRight.maxV : root->val;
        }
        else {
            ansThis.isValid = false;
            ansThis.size = max(ansLeft.size, ansRight.size);
        }

        return ansThis;
    }
    bool isValid(ansT ansLeft, ansT ansRight, TreeNode *root) {
        if (!ansLeft.isValid) return false;
        if (!ansRight.isValid) return false;
        if (root->left && (ansLeft.maxV >= root->val)) return false;
        if (root->right && (ansRight.minV <= root->val)) return false;
        return true;
    }
};
