class Solution {
public:
    bool exist(vector<vector<char>> &board, string word) {
        this->word = word;
        n = board.size();
        m = board[0].size();
        len = word.size();
        if (len > n * m) return false;
        vis = new bool* [n];
        for (int i = 0; i < n; i++) {
            vis[i] = new bool [m];
            memset(vis[i], false, m);
        }
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (dfs(board, 0, i, j))
                    return true;
        return false;
    }
private:
    string word;
    int n, m, len;
    bool **vis;
    bool dfs(vector<vector<char>> &board, int k, int i, int j) {
        if (!isValid(i, j)) return false;
        if (board[i][j] != word[k]) return false;
        if (k == len - 1) return true;
        vis[i][j] = true;
        if (dfs(board, k + 1, i, j - 1))
            return true;
        if (dfs(board, k + 1, i + 1, j))
            return true;
        if (dfs(board, k + 1, i - 1, j))
            return true;
        if (dfs(board, k + 1, i, j + 1))
            return true;
        vis[i][j] = false;
        return false;
    }
    bool isValid(int i, int j) {
        if (i < 0) return false;
        if (i >= n) return false;
        if (j < 0) return false;
        if (j >= m) return false;
        return !vis[i][j];
    }
};