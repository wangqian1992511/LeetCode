class Trie {
public:
    Trie() {
        memset(ch, 0, sizeof(ch));
        memset(end, 0, sizeof(end));
    }
    void insert(string s) {
        if (!ch[s[0] - 'a'])
            ch[s[0] - 'a'] = new Trie;
        if (s.size() == 1)
            end[s[0] - 'a'] = true;
        else 
            ch[s[0] - 'a']->insert(s.substr(1));
    }
    bool search(string s) {
        if (s.size() == 1)
            return end[s[0] - 'a'];
        else
            return ch[s[0] - 'a'] && ch[s[0] - 'a']->search(s.substr(1));
    }
    bool startsWith(string s) {
        if (s.size() == 1)
            return ch[s[0] - 'a'];
        else
            return ch[s[0] - 'a'] && ch[s[0] - 'a']->startsWith(s.substr(1));
    }
private:
    Trie* ch[26];
    bool end[26];
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");