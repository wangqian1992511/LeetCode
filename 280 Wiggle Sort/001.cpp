class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        bool isLarger = false;
        int n = nums.size();
        for (int i = 1; i < n; i++) {
            isLarger ^= true;
            if ((isLarger && (nums[i] < nums[i-1])) || (!isLarger && (nums[i] > nums[i-1])))
                swap(nums[i], nums[i-1]);
        }
    }
};
