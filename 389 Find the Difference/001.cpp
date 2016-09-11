class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char, int> cnt;
        for (auto ch: s)
            cnt[ch]++;
        for (auto ch: t) {
            cnt[ch]--;
            if (cnt[ch] < 0)
                return ch;
        }
        return char(0);
    }
};
