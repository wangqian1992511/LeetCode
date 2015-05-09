class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = n - 1;
        while (nums[l] > nums[r]) {
            int m = (l + r) >> 1;
            if (nums[m] >= nums[l])
                l = m + 1;
            else 
                r = m;
        }
        return nums[l];
    }
};