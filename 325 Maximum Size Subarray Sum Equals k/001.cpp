class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        unordered_map<int, int> hash;
        hash[0] = -1;
        int n = nums.size(), s = 0, ans = 0;
        for (int i = 0; i < n; i++) {
            s += nums[i];
            if (hash.find(s - k) != hash.end())
                ans = max(ans, i - hash[s - k]);
            if (hash.find(s) == hash.end())
                hash[s] = i;
        }
        return ans;
    }
};