class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        n = board.size();
        if (!n) return;
        m = board[0].size();
        if (!m) return;
        
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (board[i][j])
                    board[i][j] = 16;
                    
        int dx[] = {0, 0, 1, 1, 1, -1, -1, -1};
        int dy[] = {1, -1, 0, 1, -1, 0, 1, -1};
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                for (int k = 0; k < 8; k++)
                    if (isValid(i, j, dx[k], dy[k]))
                        board[i][j] += (board[i + dx[k]][j + dy[k]] >= 16);
                        
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) 
                if (board[i][j] >= 16) {
                    board[i][j] -= 16;
                    if (board[i][j] < 2)
                        board[i][j] = 0;
                    else if (board[i][j] > 3)
                        board[i][j] = 0;
                    else
                        board[i][j] = 1;
                }
                else if (board[i][j] == 3)
                    board[i][j] = 1;
                else
                    board[i][j] = 0;
    }
private:
    int n, m;
    bool isValid(int x, int y, int dx, int dy) {
        if (x + dx < 0) return false;
        if (y + dy < 0) return false;
        if (x + dx >= n) return false;
        if (y + dy >= m) return false;
        return true;
    }
};
