class Solution {
public:
    int countPrimes(int n) {
        bool *isPrime = new bool [n];
        fill(isPrime, isPrime + n, 1);
        int ans = 0;
        for (int i = 2; i < n; i++)
            if (isPrime[i]) {
                ans++;
                if (i <= n / i) {
                    int j = i * i;
                    while (j < n){ 
                        isPrime[j] = false;
                        j += i;
                    }
                }
            }
        return ans;
    }
};