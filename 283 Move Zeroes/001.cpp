class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int p = 0, q = 0, n = nums.size();
        while (q < n) {
            while ((p < n) && (nums[p] != 0)) p++;
            if (q <= p) q = p + 1;
            while ((q < n) && (nums[q] == 0)) q++;
            if (q < n) swap(nums[p], nums[q]);
        }
    }
};