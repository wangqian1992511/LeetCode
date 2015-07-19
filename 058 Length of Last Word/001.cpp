class Solution {
public:
    int lengthOfLastWord(string s) {
        int ans = 0, n = s.size(), cnt = 0;
        for (int i = 0; i < n; i++)
            if (s[i] != ' ')
                cnt++;
            else {
                if (cnt) ans = cnt;
                cnt = 0;
            }
        return cnt > 0 ? cnt : ans;
    }
};