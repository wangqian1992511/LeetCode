class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
        int n = s.size();
        dp = new vector<string> [n + 1];
        dp[n].push_back("");
        vis = new bool [n];
        fill(vis, vis + n, 0);
        for (int k = 1; k <= n; k++) {
            string t = s.substr(0, k);
            if (wordDict.find(t) != wordDict.end()) {
                dfs(s, k, wordDict);
                insertAns(dp[0], t, dp[k]);
            }
        }
        return dp[0];
    }
private:
    vector<string> *dp;
    bool *vis;
    void insertAns(vector<string> &ans, string t, vector<string> &s) {
        int n = s.size();
        for (int i = 0; i < n; i++)
            ans.push_back(t + s[i]);
    }
    void dfs(string &s, int i, unordered_set<string> &wordDict) {
        int n = s.size();
        if (i >= n) return;
        if (!vis[i]) {
            vis[i] = true;
            for (int k = 1; k <= n - i; k++) {
                string t = s.substr(i, k);
                if (wordDict.find(t) != wordDict.end()) {
                    dfs(s, i + k, wordDict);
                    insertAns(dp[i], " " + t, dp[i + k]);
                }
            }
        }
    }
};