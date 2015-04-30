class Solution {
public:
    int trailingZeroes(int n) {
        int ans = 0;
        int p = 5;
        while (p <= n) {
            ans += (n / p);
            if (p <= INT_MAX / 5)
                p *= 5;
            else
                break;
        }
        return ans;
    }
};