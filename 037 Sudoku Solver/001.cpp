class Solution {
public:
    void solveSudoku(vector<vector<char> > &board) {
        int map[9][9] = 
            {{0,0,0,1,1,1,2,2,2},
             {0,0,0,1,1,1,2,2,2},
             {0,0,0,1,1,1,2,2,2},
             {3,3,3,4,4,4,5,5,5},
             {3,3,3,4,4,4,5,5,5},
             {3,3,3,4,4,4,5,5,5},
             {6,6,6,7,7,7,8,8,8},
             {6,6,6,7,7,7,8,8,8},
             {6,6,6,7,7,7,8,8,8}};
        int row[9], col[9], grid[9];
        fill(row, row + 9, (1 << 9) - 1);
        fill(col, col + 9, (1 << 9) - 1);
        fill(grid, grid + 9, (1 << 9) - 1);
        for (int i = 0; i < 9; i++)
            for (int j = 0; j < 9; j++) 
                if (board[i][j] != '.') {
                    int t = 1 << (board[i][j] - '1');
                    row[i] -= t;
                    col[j] -= t;
                    grid[map[i][j]] -= t;
                }
        dfs(board, row, col, grid, map, 0, 0);
    }
private:
    bool dfs(vector<vector<char>> &board, int row[9], int col[9], int grid[9], int map[9][9], int i, int j) {
        if (i == 9) 
            return true;
        else if (j == 9) 
            return dfs(board, row, col, grid, map, i+1, 0);
        else if (board[i][j] != '.') 
            return dfs(board, row, col, grid, map, i, j+1);
        else {
            int pos = row[i] & col[j] & grid[map[i][j]];
            while (pos) {
                int t = lowbit(pos);
                pos -= t;
                row[i] -= t;
                col[j] -= t;
                grid[map[i][j]] -= t;
                board[i][j] = exp2ch(t);
                if (dfs(board, row, col, grid, map, i, j+1))
                    return true;
                row[i] += t;
                col[j] += t;
                grid[map[i][j]] += t; 
                board[i][j] = '.';
            }
            return false;
        }
    }
    inline int lowbit(int x) {
        return x & -x;
    }
    inline char exp2ch(int x) {
        switch (x) {
            case 1: return '1';
            case 2: return '2';
            case 4: return '3';
            case 8: return '4';
            case 16: return '5';
            case 32: return '6';
            case 64: return '7';
            case 128: return '8';
            case 256: return '9';
            default: return '0';
        }
    }
};