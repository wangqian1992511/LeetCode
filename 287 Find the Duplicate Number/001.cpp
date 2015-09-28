class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int tot = 0;
        for (int i = 0; i < n; i++)
            tot += nums[i];
        n--;
        int l = 1, r = n;
        while (l != r) {
            int m = (l + r) >> 1;
            int lb = (2 * n + 3 - m) * m >> 1;
            int ub = (m * (m + 1) + n * (n + 1)) >> 1;
            if (tot > ub)
                l = m + 1;
            else if (tot < lb)
                r = m - 1;
            else {
                int t = 0;
                while (true) {
                    if (isDup(nums, m + t))
                        return m + t;
                    if (isDup(nums, m - t))
                        return m - t;
                    t++;
                }
            }
        }
        return l;
    }
private:
    bool isDup(vector<int> &nums, int x) {
        int cnt = 0, n = nums.size();
        for (int i = 0; i < n; i++)
            if (nums[i] == x)
                cnt++;
        return cnt > 1;
    }
};
