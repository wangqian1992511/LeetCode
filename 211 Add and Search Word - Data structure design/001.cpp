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
        if (s[0] == '.') {
            if (s.size() == 1) {
                for (int k = 0; k < 26; k++)
                    if (end[k])
                        return true;
            }
            else {
                for (int k = 0; k < 26; k++)
                    if (ch[k] && ch[k]->search(s.substr(1)))
                        return true;
            }
            return false;
        }
        else {
            if (s.size() == 1)
                return end[s[0] - 'a'];
            else
                return ch[s[0] - 'a'] && ch[s[0] - 'a']->search(s.substr(1));
        }
    }
private:
    Trie* ch[26];
    bool end[26];
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
