class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int dist = 0;
        for (int i = 0; i < n; i++)
            if (dist >= i)
                dist = max(dist, i + nums[i]);
        return (dist >= n - 1);
    }
};