class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if (!n || !k) return 0;

        if (k >= n / 2) {
            int ans = 0;
            for (int i = 1; i < n; i++)
                ans += max(0, prices[i] - prices[i-1]);
            return ans;
        }

        int *sell, *buy, ans = 0;
        sell = new int [k + 1];
        buy = new int [k + 1];
        for (int i = 0; i <= k; i++)
            sell[i] = buy[i] = INT_MIN;

        sell[0] = buy[0] = 0;
        buy[1] = -prices[0];

        for (int i = 1; i < n; i++) {
            int j = (i + 2) >> 1;
            if (!(i & 1) && (j <= k)) {
                buy[j] = max(buy[j], sell[j - 1] - prices[i]);
                ans = max(ans, buy[j]);
            }

            for (int j = min(k, (i + 1) >> 1); j > 0; j--){
                sell[j] = max(sell[j], buy[j] + prices[i]);
                buy[j] = max(buy[j], sell[j - 1] - prices[i]);
                ans = max(ans, max(sell[j], buy[j]));
            }
        }
        return ans;
    }
};
