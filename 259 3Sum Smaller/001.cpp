class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), ans = 0;
        for (int i = 0; i < n - 2; i++) {
            int key = target - nums[i];
            int k = n - 1;
            for (int j = i + 1; j < k; j++) {
                while ((j < k) && (nums[j] + nums[k] >= key)) 
                    k--;
                ans += k - j;
            }
        }
        return ans;
    }
};