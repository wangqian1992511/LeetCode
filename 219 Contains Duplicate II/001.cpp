class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map <int, int> tot, one, two;
        int n = nums.size();
        for (int i = 0; i < n; i++)
            if (tot.find(nums[i]) == tot.end()) {
                tot[nums[i]] = 1;
                one[nums[i]] = i;
            }
            else if (tot[nums[i]] == 1) {
                tot[nums[i]] = 2;
                two[nums[i]] = i;
            }
            else
                tot[nums[i]] = 3;
        for (int i = 0; i < n; i++)
            if ((tot[nums[i]] == 2) && (two[nums[i]] - one[nums[i]] <= k))
                return true;
        return false;
    }
};
