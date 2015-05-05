class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int t, l = 0, r = nums.size() - 1;
        while (l <= r) {
            if (nums[l] == target)
                return true;
            t = nums[l];
            while ((l <= r) && (nums[l] == t))
                l++;
            if (nums[r] == target)
                return true;
            t = nums[r];
            while ((l <= r) && (nums[r] == t))
                r--;   
            if (l > r)
                break;
            int m = (l + r) >> 1;
            if (nums[m] == target)
                return true;
            else if (nums[l] <= nums[m]) {
                if ((nums[l] <= target) && (target < nums[m]))
                    r = m - 1;
                else
                    l = m + 1;
            }
            else {
                if ((nums[m] < target) && (target <= nums[r]))
                    l = m + 1;
                else
                    r = m - 1;
            }
        }
        return false;
    }
};