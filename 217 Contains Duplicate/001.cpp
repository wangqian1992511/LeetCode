class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> hash;
        int n = nums.size();
        for (int i = 0; i < n; i++)
            if (hash.find(nums[i]) == hash.end())
                hash[nums[i]] = 0;
            else
                return true;
        return false;
    }
};
