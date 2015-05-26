class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        if (!n) return 0;
        int minV, maxV, ans;
        ans = minV = maxV = nums[0];
        for (int i = 1; i < n; i++) {
            int minT = min(nums[i], min(minV * nums[i], maxV * nums[i]));
            int maxT = max(nums[i], max(minV * nums[i], maxV * nums[i]));
            ans = max(ans, maxT);
            maxV = maxT;
            minV = minT;
        }
        return ans;
    }
};
