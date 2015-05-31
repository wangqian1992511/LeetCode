class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int p = nums[i];
            while ((p > 0) && (p <= n) && (nums[p - 1] != p)) {
                swap(nums[i], nums[p - 1]);
                p = nums[i];
            }
        }
        for (int i = 0; i < n; i++)
            if (nums[i] != i + 1)
                return i + 1;
        return n + 1;
    }
};
