class Solution {
public:
    Solution(vector<int> nums) {
        data = nums;
    }

    int pick(int target) {
        int v = -1, ans = 0, idx = 0;
        for (auto it: data) {
            if (it == target) {
                if (v == -1) {
                    v = rand();
                    ans = idx;
                }
                else {
                    int x = rand();
                    if (x < v) {
                        v = x;
                        ans = idx;
                    }
                }
            }
            idx++;
        }
        return ans;
    }
private:
    vector<int> data;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int param_1 = obj.pick(target);
 */
