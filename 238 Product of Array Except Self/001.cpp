class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> f(n);
        f[0] = 1;
        for (int i = 1; i < n; i++) 
            f[i] = f[i-1] * nums[i-1];
        int r = 1; 
        for (int i = n-1; i >= 0; i--) {
            f[i] *= r;
            r *= nums[i];
        }
        return f;
    }
};