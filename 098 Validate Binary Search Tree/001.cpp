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
    int minV, maxV;
};

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return helper(root).isValid;
    }
private:
    ansT helper(TreeNode* root) {
        ansT ansThis;
        if (!root) {
            ansThis.isValid = true;
            return ansThis;
        }

        ansT ansLeft = helper(root->left);
        ansT ansRight = helper(root->right);

        if (isValid(ansLeft, ansRight, root)) {
            ansThis.isValid = true;
            ansThis.minV = root->left ? ansLeft.minV : root->val;
            ansThis.maxV = root->right ? ansRight.maxV : root->val;
        }
        else {
            ansThis.isValid = false;
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
