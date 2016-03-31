class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int *num = new int [amount + 1];
        num[0] = 0;
        sort(coins.begin(), coins.end());
        for (int i = 1; i <= amount; i++) {
            num[i] = INT_MAX - 1;
            for (auto it: coins)
                if (i - it >= 0)
                    num[i] = min(num[i], num[i - it] + 1);
                else
                    break;
        }
        return num[amount] != INT_MAX - 1 ? num[amount] : -1;
    }
};