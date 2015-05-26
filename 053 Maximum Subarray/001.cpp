class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size(), ans = INT_MIN, tmp, p = 0;
        while (p < n) {
            tmp = 0;
            while ((p < n) && (nums[p] <= 0)) 
                ans = max(nums[p++], ans);
            while ((p < n) && (nums[p] + tmp >= 0)) 
                ans= max(tmp += nums[p++], ans);
        }
        return ans;
    }
};
