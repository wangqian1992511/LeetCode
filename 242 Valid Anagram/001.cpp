class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> cnt;
        for (auto ch: s)
            cnt[ch]++;
        for (auto ch: t)
            cnt[ch]--;
        for (auto it: cnt)
            if (it.second != 0)
                return false;
        return true;
    }
};
