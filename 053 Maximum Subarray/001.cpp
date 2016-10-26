class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int tot = 0, minSum = 0, ans = INT_MIN;
        for (auto it: nums) {
            tot += it;
            ans = max(ans, tot - minSum);
            minSum = min(minSum, tot);
        }
        return ans;
    }
};
