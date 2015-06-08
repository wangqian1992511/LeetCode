class Solution {
public:
    string minWindow(string s, string t) {
        int *cnt = new int [256];
        bool *have = new bool [256];
        int n = s.size(), m = t.size();
        fill(cnt, cnt + 256, 0);
        fill(have, have + 256, 0);
        for (int i = 0; i < m; i++) {
            cnt[t[i]]++;
            have[t[i]] = true;
        }
            
        string ans = "";
        int p = 0, q = 0;
        int tot = 0, len = INT_MAX;
        while ((p < n) && (q < n)) {
            while ((p < n) && (!have[s[p]]))
                p++;
            if (q < p)
                q = p;
            while ((q < n) && (tot != m)) {
                if (have[s[q]]) {
                    cnt[s[q]]--;
                    if (cnt[s[q]] >= 0)
                        tot++;
                }
                q++;
            }
            while ((p < n) && (tot == m)) {
                if (have[s[p]]) {
                    if (q - p < len) {
                        len = q - p;
                        ans = s.substr(p, len);
                    }                    
                    cnt[s[p]]++;
                    if (cnt[s[p]] > 0)
                        tot--;
                }
                p++;
            }
        }
        return ans;
    }
};