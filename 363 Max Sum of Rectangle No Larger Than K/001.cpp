class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int a = matrix.size();
        int b = matrix[0].size();
        int n = min(a, b), m = max(a, b);
        bool rev = (n != a);
        ans = INT_MIN;

        int **sum = new int* [n];
        for (int i = 0; i < n; i++) {
            sum[i] = new int [m];
            have.clear();
            have.insert(0);
            int tSum = 0;
            for (int j = 0; j < m; j++) {
                sum[i][j] = (i ? sum[i - 1][j] : 0) + (rev ? matrix[j][i] : matrix[i][j]);
                tSum += sum[i][j];
                update(tSum, k);
            }

            for (int t = 0; t < i; t++) {
                have.clear();
                have.insert(0);
                int tSum = 0;
                for (int j = 0; j < m; j++) {
                    tSum += sum[i][j] - sum[t][j];
                    update(tSum, k);
                }
            }
        }

        return ans;
    }
private:
    set<int> have;
    int ans;
    void update(int tSum, int k) {
        int lb = tSum - k;
        auto it = have.lower_bound(lb);
        if (it != have.end())
            ans = max(ans, tSum - *it);
        have.insert(tSum);
    }
};
