class Solution {
public:
    bool wordPatternMatch(string pattern, string str) {
        this->pattern = pattern;
        this->str = str;
        fill(cnt, cnt + 26, 0);
        for (auto it = pattern.begin(); it != pattern.end(); it++)
            cnt[*it - 'a']++;
        available = str.size();
        return dfs(0, 0, 0);
    }
private:
    string pattern;
    string str;
    unordered_map<char, string> c2s;
    unordered_map<string, char> s2c;
    int cnt[26], available;
    bool dfs(int idxP, int stS, int enS) {
        if ((idxP == pattern.size()) || (enS == str.size())) {
            return (idxP == pattern.size()) && (stS == str.size());
        }
        string t = str.substr(stS, enS - stS + 1);
        char ch = pattern[idxP];
        if (c2s.find(ch) == c2s.end()) {
            if (s2c.find(t) == s2c.end()) {
                c2s[ch] = t;
                s2c[t] = ch;
                available -= cnt[ch - 'a'] * t.size();
                if (available < 0) {
                    c2s.erase(ch);
                    s2c.erase(t);
                    available += cnt[ch - 'a'] * t.size();
                    return false;
                }
                if (dfs(idxP + 1, enS + 1, enS + 1))
                    return true;
                c2s.erase(ch);
                s2c.erase(t);
                available += cnt[ch - 'a'] * t.size();
            }
        }
        else if (c2s[ch] == t) {
            if (s2c[t] == ch) {
                if (dfs(idxP + 1, enS + 1, enS + 1))
                    return true;
            }
        }
        return dfs(idxP, stS, enS + 1);
    }
    
};