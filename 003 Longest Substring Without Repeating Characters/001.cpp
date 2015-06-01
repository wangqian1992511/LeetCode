class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int p, q, n, t, ans;
        n = s.size();
        ans = t = p = q = 0;
        
        bool vis[256];
        fill(vis, vis + 256, 0);
        
        while (true) {
            while ((q < n) && (!vis[s[q]])) {
                vis[s[q]] = true;
                t++;
                q++;
            }
            
            if (t > ans)
                ans = t;
                
            if (q >= n)
                break;
            
            while (s[p] != s[q]) {
                vis[s[p]] = false;
                t--;
                p++;
            }
            
            vis[s[p]] = false;
            t--;
            p++;
        }
        
        return ans;
    }
};