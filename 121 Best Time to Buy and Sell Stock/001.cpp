class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int n = prices.size();
        if (!n) return 0;
        int minP = prices[0];
        int ans = 0;
        for (int i = 1; i < n; i++) {
            if (prices[i] - minP > ans)
                ans = prices[i] - minP;
            if (prices[i] < minP)
                minP = prices[i];
        }
        return ans;
    }
};