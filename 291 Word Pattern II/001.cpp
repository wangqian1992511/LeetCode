class Solution {
public:
    bool wordPatternMatch(string pattern, string str) {
        this->pattern = pattern;
        this->str = str;
        return dfs(0, 0, 0);
    }
private:
    string pattern;
    string str;
    unordered_map<char, string> c2s;
    unordered_map<string, char> s2c;
    bool vis[100][100][100];
    bool dfs(int idxP, int stS, int enS) {
        if ((idxP == pattern.size()) || (enS == str.size())) {
            return (idxP == pattern.size()) && (stS == str.size());
        }
        string t = str.substr(stS, enS - stS + 1);
        if (c2s.find(pattern[idxP]) == c2s.end()) {
            if (s2c.find(t) == s2c.end()) {
                c2s[pattern[idxP]] = t;
                s2c[t] = pattern[idxP];
                if (dfs(idxP + 1, enS + 1, enS + 1))
                    return true;
                c2s.erase(pattern[idxP]);
                s2c.erase(t);
            }
        }
        else if (c2s[pattern[idxP]] == t) {
            if (s2c[t] == pattern[idxP]) {
                if (dfs(idxP + 1, enS + 1, enS + 1))
                    return true;
            }
        }
        return dfs(idxP, stS, enS + 1);
    }
};
