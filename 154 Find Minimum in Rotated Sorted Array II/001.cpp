class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = n-1;
        while ((l < r) && (nums[l] >= nums[r])) {
            while ((l < r) && (nums[l] == nums[l + 1])) l++;
            while ((l < r) && (nums[r] == nums[r - 1])) r--;
            if ((l == r) || (nums[l] < nums[r])) break;
            int m = (l + r) >> 1;
            if (nums[m] >= nums[l])
                l = m + 1;
            else
                r = m;
        }
        return nums[l];
    }
};