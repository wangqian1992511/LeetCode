class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (!n) return 0;
        int bestBuy = 0, bestSell = 0, secondSell = 0, sellDay = -1;

        bestBuy = -prices[0];
        bestSell = 0;
        for (int i = 1; i < n; i++) {
            int tmpBuy = ((sellDay != i - 1) ? bestSell : secondSell) - prices[i];
            int tmpSell = bestBuy + prices[i];
            if (tmpSell > bestSell) {
                sellDay = i;
                secondSell = bestSell;
                bestSell = tmpSell;
            }
            bestBuy = max(bestBuy, tmpBuy);
        }

        return max(bestBuy, bestSell);
    }
};
