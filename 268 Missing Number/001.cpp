class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int a = 0, b = 0;
        for (int i = 0; i < n; i++) {
            a ^= (i + 1);
            b ^= nums[i];
        }
        return a ^ b;
    }
};