class Solution {
public:
    int countPrimes(int n) {
        bool *isPrime = new bool [n];
        vector<int> prime;
        fill(isPrime, isPrime + n, 1);
        int ans = 0;
        for (int i = 2; i < n; i++) {
            if (isPrime[i]) {
                ans++;
                prime.push_back(i);
            }
            for (int j = 0; j < ans; j++) {
                if (i * prime[j] >= n) break;
                isPrime[i * prime[j]] = false;
                if (! (i % prime[j])) break;
            }
        }
        return ans;
    }
};