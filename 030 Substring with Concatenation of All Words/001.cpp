class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        int m = words.size();
        if (!m) return ans;
        int k = words[0].size();
        
        unordered_map<string, int> cnt;
        for (int i = 0; i < m; i++) 
            if (cnt.find(words[i]) == cnt.end())
                cnt[words[i]] = 1;
            else
                cnt[words[i]]++;
                
        int n = s.size();
        bool *vis = new bool [n];
        fill(vis, vis + n, false);
        queue<string> que;
        
        for (int i = 0; i <= n - k; i++)
            if (!vis[i]) {
                int tot = 0;
                int q = i, p = i; 
                while (q <= n - k) {
                    string t = s.substr(q, k);
                    if (cnt.find(t) == cnt.end()) {
                        vis[q] = true;
                        break;
                    }
                    while (!cnt[t]) {
                        cnt[que.front()]++;
                        vis[p] = true;
                        p += k;
                        que.pop();
                        tot--;
                    }
                    cnt[t]--;
                    q += k;
                    que.push(t);
                    tot++;
                    if (tot == m)
                        ans.push_back(p);
                }
                while (!que.empty()) {
                    cnt[que.front()]++;
                    vis[p] = true;
                    p += k;
                    que.pop();
                    tot--;
                }
            }
            
        return ans;        
    }
};