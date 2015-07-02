class Solution {
public:
    int numTrees(int n) {
        int *t;
        t = new int [n + 1];
        fill(t, t + n + 1, 0);
        t[1] = t[0] = 1;
        for (int i = 2; i <= n; i++)
            for (int j = 0; j < i; j++)
                t[i] += (t[j] * t[i - 1 - j]);
        return t[n];
    }
};