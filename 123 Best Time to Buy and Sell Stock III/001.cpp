class Solution {
public:
    int maxProfit(vector<int>& prices) {
		int k = 2;
        int n = prices.size();
        if (!n || !k) return 0;
        
        if (k >= n / 2) {
            int ans = 0;
            for (int i = 1; i < n; i++)
                ans += max(0, prices[i] - prices[i-1]);
            return ans;
        }
        
        long long **sell, **buy;
        sell = new long long* [n];
        buy = new long long*[n];
        for (int i = 0; i < n; i++) {
            sell[i] = new long long [2];
            buy[i] = new long long [2];
            sell[i][0] = buy[i][0] = 0;
        }
        
        bool ansP = false;
        sell[0][1] = INT_MIN;
        buy[0][1] = -prices[0];
        
        long long ans = max(0, -prices[0]);
        for (int j = 1; j <= k; j++) {
            ansP = !ansP;
            for (int i = 0; i < ((j - 1) << 1); i++)
                buy[i][ansP] = sell[i][ansP] = INT_MIN;
            sell[(j - 1) << 1][ansP] = INT_MIN;
            for (int i = max(1, (j - 1) << 1); i < n; i++)
                buy[i][ansP] = max(buy[i - 1][ansP], sell[i - 1][!ansP] - prices[i]);
            for (int i = (j << 1) - 1; i < n; i++)
                sell[i][ansP] = max(sell[i - 1][ansP], buy[i - 1][ansP] + prices[i]);
            ans = max(ans, max(sell[n - 1][ansP], buy[n - 1][ansP]));
        }
        
        return ans;
    }
};