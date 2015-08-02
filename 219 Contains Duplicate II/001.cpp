class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> s;
        int n = nums.size();
        for (int i = 0; i < min(n, k); i++)
            if (s.find(nums[i]) == s.end())
                s.emplace(nums[i]);
            else
                return true;
        for (int i = k; i < n; i++)
            if (s.find(nums[i]) == s.end()) {
                s.emplace(nums[i]);
                s.erase(nums[i - k]);
            }
            else
                return true;
        return false;
    }
};