class TrieNode {
public:
    TrieNode() {
        memset(ch, 0, sizeof(ch));
    }
    void insert(string &s, int i) {
        if (i == s.size()) return;
        if (!ch[s[i] - 'a']) ch[s[i] - 'a'] = new TrieNode();
        ch[s[i] - 'a']->insert(s, i + 1);
    }
    bool search(string &s, int i) {
        if (i == s.size()) return true;
        if (s[i] == '.') {
            for (int k = 0; k < 26; k++)
                if (ch[k] && ch[k]->search(s, i + 1))
                    return true;
            return false;
        }
        else {
            if (!ch[s[i] - 'a']) return false;
            return ch[s[i] - 'a']->search(s, i + 1);
        }
    }
private:
    TrieNode* ch[27];
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }
    void insert(string s) {
        s = s + '{';
        root->insert(s, 0);
    }
    bool search(string key) {
        key = key + '{';
        return root->search(key, 0);
    }
    bool startsWith(string prefix) {
        return root->search(prefix, 0);
    }
private:
    TrieNode* root;
};

class WordDictionary {
public:
    void addWord(string word) {
        T.insert(word);
    }
    bool search(string word) {
        return T.search(word);
    }
private:
    Trie T;
};
