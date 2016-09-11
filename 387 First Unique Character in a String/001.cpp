class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> idx;
        for (int i = 0; i < s.size(); i++) {
            char ch = s[i];
            if (idx.count(ch))
                idx[ch] = INT_MAX;
            else
                idx[ch] = i;
        }
        int ans = INT_MAX;
        for (auto it: idx)
            ans = min(ans, it.second);
        return (ans == INT_MAX) ? -1 : ans;
    }
};
