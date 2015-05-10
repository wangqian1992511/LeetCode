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
        if (root) {
            TreeLinkNode *l, *r;
            l = root->left;
            r = root->right;
            connect(l);
            connect(r);            
            while (l) {
                l->next = r;
                l = l->right;
                r = r->left;
            }
        }
    }
};