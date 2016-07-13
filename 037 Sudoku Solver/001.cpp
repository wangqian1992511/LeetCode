class Solution {
public:
    void solveSudoku(vector<vector<char> > &board) {
        for (int i = 1; i <= 9; i++)
            exp2ch[1 << (i - 1)] = '0' + i;

        fill(row, row + 9, (1 << 9) - 1);
        fill(col, col + 9, (1 << 9) - 1);
        fill(grid, grid + 9, (1 << 9) - 1);

        for (int i = 0; i < 9; i++)
            for (int j = 0; j < 9; j++)
                if (board[i][j] != '.') {
                    int t = 1 << (board[i][j] - '1');
                    row[i] -= t;
                    col[j] -= t;
                    grid[area[i][j]] -= t;
                }

        dfs(board, 0, 0);
    }
private:
    unordered_map<int, char> exp2ch;
    int row[9], col[9], grid[9];
    int area[9][9] =
        {{0,0,0,1,1,1,2,2,2},
         {0,0,0,1,1,1,2,2,2},
         {0,0,0,1,1,1,2,2,2},
         {3,3,3,4,4,4,5,5,5},
         {3,3,3,4,4,4,5,5,5},
         {3,3,3,4,4,4,5,5,5},
         {6,6,6,7,7,7,8,8,8},
         {6,6,6,7,7,7,8,8,8},
         {6,6,6,7,7,7,8,8,8}};
    bool dfs(vector<vector<char>> &board, int i, int j) {
        if (i == 9)
            return true;
        else if (j == 9)
            return dfs(board, i + 1, 0);
        else if (board[i][j] != '.')
            return dfs(board, i, j + 1);
        else {
            int pos = row[i] & col[j] & grid[area[i][j]];
            while (pos) {
                int t = lowbit(pos);
                pos -= t;
                row[i] -= t;
                col[j] -= t;
                grid[area[i][j]] -= t;
                board[i][j] = exp2ch[t];
                if (dfs(board, i, j + 1))
                    return true;
                row[i] += t;
                col[j] += t;
                grid[area[i][j]] += t;
                board[i][j] = '.';
            }
            return false;
        }
    }
    int lowbit(int x) {
        return x & -x;
    }
};
