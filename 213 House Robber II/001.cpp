class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (!n) return 0;
        if (n == 1) return nums[0];
        int a = 0, b = 0, t;
        for (int i = 0; i < n-1; i++) {
            t = a;
            a = b;
            b = max(b, t + nums[i]);
        }
        int ans = b;
        a = b = 0;
        for (int i = 1; i < n; i++) {
            t = a;
            a = b;
            b = max(b, t + nums[i]);
        }
        return max(ans , b);
    }
};