class Solution {
public:
    int mySqrt(int x) {
        double a = x;
        while (fabs(a * a - x) >= 1) 
            a = (a + x / a) / 2;
        return int(a);
    }
};