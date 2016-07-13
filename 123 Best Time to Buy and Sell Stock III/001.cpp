class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (!n) return 0;

        int *sell, *buy, ans = 0;
        sell = new int [3];
        buy = new int [3];
        sell[1] = sell[2] = buy[2] = INT_MIN;
        sell[0] = buy[0] = 0;
        buy[1] = -prices[0];

        for (int i = 1; i < n; i++) {
            if (!i || (i == 2)) {
                int j = (i + 2) >> 1;
                buy[j] = max(buy[j], sell[j - 1] - prices[i]);
                ans = max(ans, buy[j]);
            }

            for (int j = min(2, (i + 1) >> 1); j > 0; j--){
                sell[j] = max(sell[j], buy[j] + prices[i]);
                buy[j] = max(buy[j], sell[j - 1] - prices[i]);
                ans = max(ans, max(sell[j], buy[j]));
            }
        }
        return ans;
    }
};
