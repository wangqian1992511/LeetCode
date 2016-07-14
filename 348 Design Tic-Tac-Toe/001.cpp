class TicTacToe {
public:
    /** Initialize your data structure here. */
    TicTacToe(int n) {
        this->n = n;
        row = new int [n];
        fill(row, row + n, 0);
        col = new int [n];
        fill(col, col + n, 0);
        diag = rev = 0;
    }

    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int r, int c, int p) {
        int t = (p == 1) ? 1 : -1;
        row[r] += t;
        col[c] += t;
        diag += (r == c) ? t : 0;
        rev += (r + c == n - 1) ? t : 0;
        if (haveWinner(r, c))
            return p;
        return 0;
    }
private:
    int *row, *col, diag, rev, n;
    bool haveWinner(int r, int c) {
        if (abs(row[r]) == n) return true;
        if (abs(col[c]) == n) return true;
        if (abs(diag) == n) return true;
        if (abs(rev) == n) return true;
        return false;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe obj = new TicTacToe(n);
 * int param_1 = obj.move(row,col,player);
 */
