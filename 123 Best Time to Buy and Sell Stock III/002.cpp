class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (!n) return 0;

        int minP = prices[0];
        vector<int> front (n, 0);
        for (int i = 1; i < n; i++) {
            minP = min(minP, prices[i]);
            front[i] = max(front[i - 1], prices[i] - minP);
        }

        int profit = front[n - 1];
        int maxP = prices[n - 1];
        vector<int> back (n, 0);
        for (int i = n - 2; i >= 0; i--) {
            maxP = max(maxP, prices[i]);
            back[i] = max(back[i + 1], maxP - prices[i]);
            profit = max(profit, front[i] + back[i + 1]);
        }

        return profit;
    }
};
