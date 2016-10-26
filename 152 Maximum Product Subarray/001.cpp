class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int minV = 1, maxV = 1, ans = INT_MIN;
        for (auto it: nums) {
            int preMin = minV, preMax = maxV;
            minV = min(it, min(it * preMin, it * preMax));
            maxV = max(it, max(it * preMin, it * preMax));
            ans = max(ans, maxV);
        }
        return ans;
    }
};
