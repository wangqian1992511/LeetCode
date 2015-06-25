/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        insertLeft(root);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return ! s.empty();
    }

    /** @return the next smallest number */
    int next() {
        TreeNode *v;
        v = s.top();
        s.pop();
        insertLeft(v->right);
        return v->val;
    }
private:
    stack<TreeNode *> s;
    void insertLeft(TreeNode *root) {
        if (root) {
            s.push(root);
            insertLeft(root->left);
        }
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */