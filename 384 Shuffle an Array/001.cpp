class Solution {
public:
    Solution(vector<int> nums) {
        original = nums;
        n = nums.size();
    }

    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return original;
    }

    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> nums = original;
        for (int i = n - 1; i >= 0; i--) {
            int j = rand() % (i + 1);
            swap(nums[i], nums[j]);
        }
        return nums;
    }
private:
    vector<int> original;
    int n;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * vector<int> param_1 = obj.reset();
 * vector<int> param_2 = obj.shuffle();
 */
