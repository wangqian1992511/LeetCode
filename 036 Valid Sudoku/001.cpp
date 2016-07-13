class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        const int area[9][9] =
            {{18,18,18,19,19,19,20,20,20},
             {18,18,18,19,19,19,20,20,20},
             {18,18,18,19,19,19,20,20,20},
             {21,21,21,22,22,22,23,23,23},
             {21,21,21,22,22,22,23,23,23},
             {21,21,21,22,22,22,23,23,23},
             {24,24,24,25,25,25,26,26,26},
             {24,24,24,25,25,25,26,26,26},
             {24,24,24,25,25,25,26,26,26}};
        bool v[27][9] = {0};
        for (int i = 0; i < 9; i++)
            for (int j = 0; j < 9; j++)
                if (board[i][j] != '.') {
                    int k = board[i][j] - '1';
                    if (v[i][k] || v[j + 9][k] || v[area[i][j]][k])
                        return false;
                    v[i][k] = v[j + 9][k] = v[area[i][j]][k] = true;
                }
        return true;
    }
};
