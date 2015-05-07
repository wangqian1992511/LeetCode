class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int i = 0, dist = 0, far = 0, ans = 0;
        while (dist < n - 1) {
            if (dist < i)
                return INT_MAX;
            ans++;
            while (i <= far) {
                dist = max(dist, i + nums[i]);
                i++;
            }
            far = dist;
        }
        return ans;
    }
};