class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int cnt[256];
        fill(cnt, cnt + 256, 0);
        for (auto ch: magazine)
            cnt[ch]++;
        for (auto ch: ransomNote) {
            cnt[ch]--;
            if (cnt[ch] < 0)
                return false;
        }
        return true;
    }
};
