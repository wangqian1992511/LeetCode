class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> s;
        int n = nums.size();
        for (int i = 0; i < n; i++)
            if (s.find(nums[i]) == s.end())
                s.emplace(nums[i]);
            else
                return true;
        return false;
    }
};