class Solution {
public:
    int numIslands(vector<vector<char>> &grid) {
        n = grid.size();
        if (!n) return 0;
        m = grid[0].size();
        if (!m) return 0;
        vis = new bool* [n];
        for (int i = 0; i < n; i++) 
            vis[i] = new bool [m];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                vis[i][j] = (grid[i][j] == '0');
        int ans = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (isValid(i, j)) {
                    ans++;
                    dfs(i,j);
                }
        return ans;
    }
private:
    int n, m;
    bool **vis;
    bool isValid(int i, int j) {
        if (i >= n) return false;
        if (i < 0) return false;
        if (j >= m) return false;
        if (j < 0) return false;
        if (vis[i][j]) return false;
        return true;
    }
    void dfs(int i, int j) {
        vis[i][j] = true;
        if (isValid(i-1, j)) dfs(i-1, j);
        if (isValid(i+1, j)) dfs(i+1, j);
        if (isValid(i, j-1)) dfs(i, j-1);
        if (isValid(i, j+1)) dfs(i, j+1);
    }
};