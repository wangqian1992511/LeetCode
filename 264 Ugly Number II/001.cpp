class Solution {
public:
    int nthUglyNumber(int n) {
        int m = 3, ans = 1;
        int* primes = new int [3];
        int* idx = new int [3];
        int* num = new int [n];
        fill(idx, idx + m, 0);
        primes[0] = 2;
        primes[1] = 3;
        primes[2] = 5;

        num[0] = 1;
        for (int t = 1; t < n; t++) {
            int tmp = INT_MAX;
            for (int i = 0; i < m; i++) {
                while (num[idx[i]] * primes[i] <= ans)
                    idx[i]++;
                tmp = min(tmp, num[idx[i]] * primes[i]);
            }
            num[t] = ans = tmp;
        }
        return ans;
    }
};
