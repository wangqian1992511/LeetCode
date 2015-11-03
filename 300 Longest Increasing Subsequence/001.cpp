class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        int *cand = new int [n + 1];
        fill(cand, cand + n + 1, INT_MAX);
        cand[0] = INT_MIN;
        for (int i = 0; i < n; i++) {
            int l = 0, r = n;
            while (l != r) {
                int m = l + (r - l) / 2;
                if (cand[m] < nums[i])
                    l = m + 1;
                else
                    r = m;
            }
            cand[l] = nums[i];
            ans = max(ans, l);
        }
        return ans;
    }
};
