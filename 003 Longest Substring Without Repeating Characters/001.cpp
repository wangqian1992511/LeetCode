class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int p = 0, q = 0, ans = 0;
        bool hasChar[256];
        fill(hasChar, hasChar + 256, false);
        while (q < int(s.size())) {
            while (hasChar[s[q]])
                hasChar[s[p++]] = false;
            while ((q < int(s.size())) && (!hasChar[s[q]]))
                hasChar[s[q++]] = true;
            ans = max(ans, q - p);
        }
        return ans;
    }
};
