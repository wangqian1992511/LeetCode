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
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        int cnt = 0;
        if (root) {
            q.push(root);
            cnt = 1;
        }
        bool isLeft = true;
        while (!q.empty()) {
            vector<int> tmp;
            int tCnt = 0;
            for (int i = 0; i < cnt; i++) {
                TreeNode *node = q.front();
                tmp.push_back(node->val);
                if (node->left) {
                    q.push(node->left);
                    tCnt++;
                }
                if (node->right) {
                    q.push(node->right);
                    tCnt++;
                }
                q.pop();
            } 
            if (!isLeft)
                for (int i = 0; i < (cnt >> 1); i++) {
                    int k = tmp[i];
                    tmp[i] = tmp[cnt - i - 1];
                    tmp[cnt - i - 1] = k;
                }
            ans.push_back(tmp);
            cnt = tCnt;
            isLeft = !isLeft;
        }
        return ans;
    }
};