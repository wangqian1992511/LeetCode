class Solution {
public:
    int countPrimes(int n) {
        bool *isPrime = new bool [n];
        vector<int> prime;
        fill(isPrime, isPrime + n, 1);
        int ans = 0;
        for (int i = 2; i < n; i++)
            if (isPrime[i]) {
                ans++;
                prime.push_back(i);
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