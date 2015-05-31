class Solution {
public:
    int64_t divide(int64_t dividend, int64_t divisor) {
        if (!divisor) return INT_MAX;
        
        bool neg = false;
        if (dividend < 0) {
            neg = !neg;
            dividend = -dividend;
        }
        if (divisor < 0) {
            neg = !neg;
            divisor = -divisor;
        }
        
        int64_t t = divisor;
        while ((divisor << 1) <= dividend)
            divisor <<= 1;
            
        int64_t ans = 0;
        while (divisor >= t) {
            ans <<= 1;
            if (divisor <= dividend) {
                ans++;
                dividend -= divisor;
            }
            divisor >>= 1;
        }
        
        if (neg) 
            ans = -ans;
        return ((ans > INT_MAX) || (ans < INT_MIN)) ? INT_MAX : ans;
    }
};
