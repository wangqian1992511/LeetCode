class Solution {
public:
    int numWays(int n, int k) {
        if (!k) return 0;
        if (n == 0) return 0;
        if (n == 1) return k;
        if (n == 2) return k * k;
        int a = k, b = k * k;
        for (int i = 3; i <= n; i++) {
            int t = (k-1) * (a + b);
            a = b;
            b = t;
        }
        return b;
    }
};
