class Solution {
public:
    int countDigitOne(int64_t n) {
        int ans = 0;
        int64_t d = 1;
        while (d <= n) {
            ans += n / 10 / d * d + min(d, max(int64_t(0), 1 + n % (d * 10) - d));
            d *= 10;
        }
        return ans;
    }
};