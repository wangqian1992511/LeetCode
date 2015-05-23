class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        return qSearch(nums, 0, n - 1, k - 1);
    }
private:
    int qSearch(vector<int> &nums, int st, int en, int k) {
        if (st == en)  return nums[st];
        int l = st, r = en;
        int key = nums[(st + en) >> 1];
        while (l < r) {
            while (nums[l] > key) l++;
            while (nums[r] < key) r--;
            if (l <= r) {
                swap(nums[l], nums[r]);
                l++; 
                r--;
            }
        }
        if (k <= r)
            return qSearch(nums, st, r, k);
        else if (k >= l)
            return qSearch(nums, l, en, k);
        else
            return nums[r + 1];
    }
};
