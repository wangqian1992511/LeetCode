class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        return helper(0, nums.size() - 1, nums, k - 1);
    }
private:
    int helper(int st, int en, vector<int>& nums, int k) {
        int l = st, r = en;
        int m = l + (r - l) / 2;
        int key = nums[m];

        while (l <= r) {
            while (nums[l] > key)
                l++;
            while (nums[r] < key)
                r--;
            if (l <= r) {
                swap(nums[l], nums[r]);
                l++;
                r--;
            }
        }

        if (k <= r)
            return helper(st, r, nums, k);
        else if (k >= l)
            return helper(l, en, nums, k);
        else
            return nums[k];
    }
};
