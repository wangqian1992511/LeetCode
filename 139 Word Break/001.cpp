class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        int n = s.size();
        bool *dp = new bool [n];
        for (int i = 0; i < n; i++) {
            dp[i] = (wordDict.find(s.substr(0, i + 1)) != wordDict.end());
            for (int j = 0; j < i; j++)
                dp[i] |= (dp[j] && (wordDict.find(s.substr(j + 1, i - j)) != wordDict.end()));
        }
        return dp[n - 1];
    }
};
