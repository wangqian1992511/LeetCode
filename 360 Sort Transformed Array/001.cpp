class Solution {
public:
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
        int p = -1, n = nums.size();
        if (a) {
            double m = -b * 0.5 / a;
            while ((p + 1 < n) && (nums[p + 1] <= m))
                p++;
        }

        int q = p + 1;
        vector<int> ans;
        bool isReversed = (a < 0);
        while ((p >= 0) && (q < n))
            if ((calc(nums[p], a, b, c) < calc(nums[q], a, b, c)) ^ isReversed)
                ans.push_back(calc(nums[p--], a, b, c));
            else
                ans.push_back(calc(nums[q++], a, b, c));
        while (p >= 0)
            ans.push_back(calc(nums[p--], a, b, c));
        while (q < n)
            ans.push_back(calc(nums[q++], a, b, c));

        if (isReversed)
            reverse(ans.begin(), ans.end());
        return ans;
    }
private:
    int calc(int x, int a, int b, int c) {
        return (a * x + b) * x + c;
    }
};
