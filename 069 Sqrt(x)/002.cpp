class Solution {
public:
    int mySqrt(int x) {
        if (x <= 1) return x;
        int l = 1; 
        int r = x;
        while (r - l > 1) {
            int m = int(l / 2.0 + r / 2.0);
            if (m  == x / m)
                return m;
            else if (m < x / m)
                l = m;
            else 
                r = m;
        }
        return l;
    }
};