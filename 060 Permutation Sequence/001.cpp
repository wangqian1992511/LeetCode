class Solution {
public:
    string getPermutation(int n, int k) {
        int fact[10] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};
        bool vis[10] = {0};
        string ans = "";
        k--;
        for (int i = n - 1; i >= 0; i--) {
            int p = k / fact[i];
            k %= fact[i];
            int j = 0, t = 0;
            for (j = 1; j < 10; j++)
                if (! vis[j]) {
                    if (t == p) 
                        break;
                    t++;
                }
            vis[j] = true;
            ans += char(j + '0');
        }
        return ans;
    }
};