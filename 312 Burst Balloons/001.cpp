class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        int **dp = new int* [n + 2];
        for (int i = 0; i <= n + 1; i++) {
            dp[i] = new int [n + 2];
            fill(dp[i], dp[i] + n + 2, 0);
        }
        vector<int> data;
        data.push_back(1);
        for (auto it: nums)
            data.push_back(it);
        data.push_back(1);
        for (int i = 1; i <= n; i++)
            dp[i][i] = data[i-1] * data[i] * data[i+1];
        for (int i = 1; i < n; i++)
            for (int j = i + 1; j <= n; j++)
                for (int k = i; k <= j; k++)
                    dp[i][j] = max(dp[i][j], dp[i][k-1] + dp[k+1][j] + data[k]);
        return dp[1][n];
    }
    
};