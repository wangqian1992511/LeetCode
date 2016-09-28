class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        if (!k) return 0;
        k = max(min(int(s.size()), k), 0);

        map<int, char> idx;
        unordered_map<char, int> ch2idx;
        int p = 0, q = 0, ans = 0;
        for (char ch: s) {
            if (ch2idx.count(ch))
                idx.erase(ch2idx[ch]);
            ch2idx[ch] = q;
            idx[q] = ch;
            q++;

            if (idx.size() > k) {
                auto it = idx.begin();
                p = it->first + 1;
                idx.erase(it);
            }
            ans = max(ans, q - p);
        }

        return ans;
    }
};
