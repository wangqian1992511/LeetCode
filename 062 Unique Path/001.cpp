class Solution {
public:
    int uniquePaths(int m, int n) {
        if (m < n) swap(m, n);
        int* c[2];
        bool ans = false;
        c[0] = new int [n + 1];
        c[1] = new int [n + 1];
        for (int i = 0; i <= n; i++)
            c[0][i] = c[1][i] = 0;
        c[ans][1] = 1;
        
        for (int i = 0; i < m; i++) {
            ans = !ans;
            for (int j = 1; j <= n; j++)
                c[ans][j] = c[ans][j - 1] + c[!ans][j];
        }
                
        return c[ans][n];
    }
};