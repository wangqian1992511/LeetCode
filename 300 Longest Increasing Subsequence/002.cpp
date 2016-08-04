class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (!n) return 0;

        int *lenMin = new int [n + 1];
        fill(lenMin, lenMin + n + 1, INT_MAX);

        int ans = 0;
        for (auto it: nums) {
            int l = 1, r = n;
            while (l != r) {
                int m = l + (r - l) / 2;
                if (lenMin[m] < it)
                    l = m + 1;
                else
                    r = m;
            }
            lenMin[l] = it;
            ans = max(l, ans);
        }
        return ans;
    }
};
