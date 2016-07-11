class Solution {
public:
    double myPow(double x, int64_t n) {
        if (n < 0)
            return 1 / pow(x,-n);
        if (!n)
            return 1;
        if (n == 1)
            return x;
        double t = pow(x,n >> 1);
        t = t * t;
        if (n & 1)
            return x * t;
        return t;
    }
};
