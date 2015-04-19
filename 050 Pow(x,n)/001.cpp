class Solution {
public:
    double pow(double x, int64_t n) {
        if (n < 0)
            return 1 / pow(x, -n);
        else if (n == 0)
            return 1;
        else if (n == 1)
            return x;
        else if (n & 1) {
            double t = pow(x, n >> 1);
            return x * t * t;
        }
        else {
            double t = pow(x, n >> 1);
            return t * t;
        }
    }
};