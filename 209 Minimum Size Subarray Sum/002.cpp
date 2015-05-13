class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        vector<int> cum;
        int n = nums.size();
        int t = 0;
        for (int i = 0; i < n; i++) {
            t += nums[i];
            cum.push_back(t);
        }
        
        int ans = INT_MAX;
        for (int i = 0; i < n; i++) {
            int l = i, r = n - 1;
            if (cum[r] - cum[l] + nums[l] < s)
                break;
            while (l < r) {
                int m = (l + r) >> 1;
                if (cum[m] - cum[i] + nums[i] < s)
                    l = m + 1;
                else
                    r = m; 
            }
            ans = min(ans, l - i + 1);
        }
		
        return ans == INT_MAX ? 0 : ans;
    }
};