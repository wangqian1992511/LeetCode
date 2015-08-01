class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size())
            return false;
        int n = s.size();
        int cnt[26];
        fill(cnt, cnt + 26, 0);
        for (int i = 0; i < n; i++) {
            cnt[s[i] - 'a']++;
            cnt[t[i] - 'a']--;
        }
        for (int i = 0; i < 26; i++)
            if (cnt[i])
                return false;
        return true;
    }
};