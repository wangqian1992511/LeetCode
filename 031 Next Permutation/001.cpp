class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        for (int i = n-1; i > 0; i--) 
            if (nums[i] > nums[i-1]) 
                for (int j = n-1; j >= i; j--)
                    if (nums[j] > nums[i - 1]) {
                        swap(nums[i-1], nums[j]);
                        swapVec(nums, i);
                        return;
                    }
        swapVec(nums, 0);
    }
private:
    void swapVec(vector<int> &nums, int l) {
        int r = nums.size() - 1;
        while (l < r) {
            swap(nums[l], nums[r]);
            l++;
            r--;
        }
    }
};
