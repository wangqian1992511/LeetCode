class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        if (!k) return 0;
        int n = s.size();
        k = max(min(n, k), 0);

        unordered_map<char, int> cnt;
        int p = 0, q = 0, ans = 0, tot = 0;
        while (q < n) {
            if ((cnt[s[q]] > 0) || (tot < k)) {
                if (!cnt[s[q]])
                    tot++;
                cnt[s[q]]++;
                q++;
                ans = max(ans, q - p);
            }
            else {
                cnt[s[p]]--;
                if (!cnt[s[p]])
                    tot--;
                p++;
            }
        }
        return ans;
    }
};
