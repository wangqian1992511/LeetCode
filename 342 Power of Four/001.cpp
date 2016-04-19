class Solution {
public:
    bool isPowerOfFour(int x) {
        int t = sqrt(x + 1e-10);
        return (x > 0) && (x == (x & -x)) && (t * t == x);
    }
};