class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (!n) return 0;

        int *len = new int [n];
        fill(len, len + n, 1);

        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++)
                if (nums[j] < nums[i])
                    len[i] = max(len[i], len[j] + 1);
            ans = max(ans, len[i]);
        }
        return ans;
    }
};
