class Solution {
public:
    int minTotalDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        if (!n) return 0;
        int m = grid[0].size();
        if (!m) return 0;
        vector<int> x, y;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) 
                if (grid[i][j]) {
                    x.push_back(i);
                    y.push_back(j);
                }
        sort(x.begin(), x.end());
        sort(y.begin(), y.end());
        n = x.size();
        int ans = 0, x0 = x[n >> 1], y0 = y[n >> 1];
        for (int i = 0; i < n; i++)
            ans += abs(x[i] - x0) + abs(y[i] - y0);
        return ans;
    }
};
