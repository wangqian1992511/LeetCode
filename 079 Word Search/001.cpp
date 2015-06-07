class Solution {
public:
    bool exist(vector<vector<char>> &board, string word) {
        int n = board.size();
        if (!n) return false;
        int m = board[0].size();
        if (!m) return false;
        int l = word.size();
        bool **vis = new bool* [n];
        for (int i = 0; i < n; i++)
            vis[i] = new bool [m];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                vis[i][j] = false;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (dfs(vis, board, word, l, 0, i, j, n, m))
                    return true;
        return false;
    }
private:
    bool dfs(bool **vis, vector<vector<char>> &board, string word, int len, int k, int i, int j, int n, int m) {
        if (board[i][j] != word[k]) return false;
        if (k == len - 1) return true;
        vis[i][j] = true;        
        if (isValid(i + 1, j, n ,m) && !vis[i + 1][j] && dfs(vis, board, word, len, k + 1, i + 1, j, n, m))
            return true;
        if (isValid(i - 1, j, n ,m) && !vis[i - 1][j] && dfs(vis, board, word, len, k + 1, i - 1, j, n, m))
            return true; 
        if (isValid(i, j + 1, n ,m) && !vis[i][j + 1] && dfs(vis, board, word, len, k + 1, i, j + 1, n, m))
            return true;
        if (isValid(i, j - 1, n ,m) && !vis[i][j - 1] && dfs(vis, board, word, len, k + 1, i, j - 1, n, m))
            return true;
        vis[i][j] = false;
        return false;
    }
    bool isValid(int i, int j, int n, int m) {
        if (i < 0) return false;
        if (i >= n) return false;
        if (j < 0) return false;
        if (j >= m) return false;
        return true;
    }
};