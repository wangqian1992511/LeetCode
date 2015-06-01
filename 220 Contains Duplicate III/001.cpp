class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if (k <= 0 || t < 0)
            return false;
        int n = nums.size();
        multiset<int64_t> s;
        for (int i = 0; i < n; i++) {
            if (i > k) 
                s.erase(s.find(nums[i - k - 1]));
            int64_t a = nums[i];
            if (s.lower_bound(a - t) != s.upper_bound(a + t))
                return true; 
            s.insert(a);
        }
        return false;
    }
};