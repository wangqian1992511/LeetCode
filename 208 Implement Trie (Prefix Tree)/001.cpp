class TrieNode {
public:
    TrieNode() {
        ch = '@';
        left = NULL;
        right = NULL;
    }
    void insert(string s) {
        int n = s.size();
        TrieNode *p = this;
        for (int i = 0; i < n; i++) {
            while ((p->ch != s[i]) && p->right)
                p = p->right;
            if (p->ch != s[i]) {
                TrieNode *q = new TrieNode();
                q->ch = s[i++];
                p->right = q;
                p = q;
                while (i < n) {
                    q = new TrieNode();
                    q->ch = s[i++];
                    p->left = q;
                    p = q;
                }
            }
            else
                p = p->left;
        }
    }
    bool search(string s) {
        int n = s.size();
        TrieNode *p = this;
        for (int i = 0; i < n; i++) {
            while ((p->ch != s[i]) && p->right)
                p = p->right;
            if (p->ch != s[i])
                return false;
            else
                p = p->left;
        }
        return true;
    }
private:
    char ch;
    TrieNode *left, *right;
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }
    void insert(string s) {
        root->insert(s + '@');
    }
    bool search(string key) {
        return root->search(key + '@');
    }
    bool startsWith(string prefix) {
        return root->search(prefix);
    }

private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");