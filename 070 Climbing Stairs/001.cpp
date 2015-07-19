class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2) return n;
        int aI, aIm1, aIm2;
        aIm1 = 2; aIm2 = 1;
        for (int i = 3; i <= n; i++) {
            aI = aIm1 + aIm2;
            aIm2 = aIm1;
            aIm1 = aI;
        }
        return aI;
    }
};