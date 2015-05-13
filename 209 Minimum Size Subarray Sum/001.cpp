class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int p = 0, q = 0, n = nums.size();
        int ans = INT_MAX, len = 0, tot = 0;
        while (q < n) {
            while ((q < n) && (tot < s)) {
                tot += nums[q];
                q++;
                len++;
            }
            while ((p < q) && (tot >= s)) {
                ans = min(ans, len);
                tot -= nums[p];
                p++;
                len--;
            }
        }
        return ans == INT_MAX ? 0 : ans;
    }
};