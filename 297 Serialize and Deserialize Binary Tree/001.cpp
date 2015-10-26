/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans = "";
        queue<TreeNode*> q;
        pushIt(ans, q, root);
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            pushIt(ans, q, node->left);
            pushIt(ans, q, node->right);
        }
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        TreeNode* ans;
        queue<TreeNode*> q;
        stringstream ss (data);
        string str;
        ss >> str;
        popIt(str, q, ans);
        while (ss >> str) {
            TreeNode* par = q.front();
            q.pop();
            popIt(str, q, par->left);
            ss >> str;
            popIt(str, q, par->right);
        }
        return ans;
    }
    
private:
    void pushIt(string &ans, queue<TreeNode*> &q, TreeNode* root) {
        if (root) {
            q.push(root);
            ans += to_string(root->val) + " ";
        }
        else
            ans += "@ ";
    }
    
    void popIt(string &str, queue<TreeNode*> &q, TreeNode* &root) {
        if (str == "@")
            root = NULL;
        else {
            TreeNode* son = new TreeNode (stoi(str));
            root = son;
            q.push(son);
        }
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
