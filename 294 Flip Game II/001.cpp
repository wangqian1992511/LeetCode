class Solution {
public:
    bool canWin(string s) {
        int n = s.size();
        unordered_map<string, bool> hash;
        if (hash.find(s) == hash.end()) {
            hash[s] = false;
            for (int i = 1; i < n; i++)
                if (s[i-1] == '+' && s[i] == '+') {
                    hash[s] |= !canWin(s.substr(0, i-1) + "--" + s.substr(i + 1, n - i - 1));
                    if (hash[s])
                        break;
                }
        }
        return hash[s];
    }
};