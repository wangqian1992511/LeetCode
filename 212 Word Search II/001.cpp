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
        if (!ch[s[i] - 'a']) return false;
        return ch[s[i] - 'a']->search(s, i + 1);
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

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        n = words.size();
        if (!n) return ans;
        for (int i = 0; i < n; i++)
            trie.insert(words[i]);
        
        n = board.size();
        m = board[0].size();
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                vis = new bool* [n];
                for (int k = 0; k < n; k++)
                    vis[k] = new bool [m];
                dfs(i, j, "", board);
            }
            
        return ans;
    }
private:
    vector<string> ans;
    unordered_set<string> dict;
    bool **vis;
    int n, m;
    Trie trie;
    void dfs(int i, int j, string tmp, vector<vector<char>>& board) {
        vis[i][j] = true;
        tmp += board[i][j];
        if (trie.startsWith(tmp)) {
            if (isValid(i-1, j)) dfs(i-1, j, tmp, board);
            if (isValid(i+1, j)) dfs(i+1, j, tmp, board);
            if (isValid(i, j-1)) dfs(i, j-1, tmp, board);
            if (isValid(i, j+1)) dfs(i, j+1, tmp, board);
        }
        if (trie.search(tmp) && (dict.find(tmp) == dict.end())) {
            dict.emplace(tmp);
            ans.push_back(tmp);
        }
        vis[i][j] = false;
    }
    bool isValid(int i, int j) {
        if (i < 0) return false;
        if (j < 0) return false;
        if (i >= n) return false;
        if (j >= m) return false;
        return !vis[i][j];
    }
};