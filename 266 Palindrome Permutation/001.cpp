class Solution {
public:
    bool canPermutePalindrome(string s) {
        int cnt[256] = {0}, n = s.size();
        for (int i = 0; i < n; i++)
            cnt[s[i]]++;
        int odd = 0;
        for (int i = 0; i < 256; i++)
            odd += (cnt[i] & 1);
        return (odd == 0) || (odd == 1);
    }
};