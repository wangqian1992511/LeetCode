class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int m = primes.size(), ans = 1;
        int* idx = new int [m];
        int* num = new int [n];
        fill(idx, idx + m, 0);

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
