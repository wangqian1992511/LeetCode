class Solution {
public:
    void solve(vector<vector<char>> &board) {
        n = board.size();
        if (!n) return;
        m = board[0].size();
        if (!m) return;
        
        vis = new bool* [n];
        for (int i = 0; i < n; i++) {
            vis[i] = new bool [m];
            for (int j = 0; j < m; j++) 
                vis[i][j] = (board[i][j] == 'X');
        }
        
        queue<pair<int,int>> q;
        for (int i = 0; i < n; i++) {
            if (!vis[i][0]) {
                vis[i][0] = true;
                q.push(make_pair(i, 0));
            }
            if (!vis[i][m-1]) {
                vis[i][m-1] = true;
                q.push(make_pair(i, m-1));
            }
        }
        for (int j = 0; j < m; j++) {
            if (!vis[0][j]) {
                vis[0][j] = true;
                q.push(make_pair(0, j));
            }
            if (!vis[n-1][j]) {
                vis[n-1][j] = true;
                q.push(make_pair(n-1, j));
            }            
        }    
        
        while (!q.empty()) {
            pair<int, int> p = q.front();
            q.pop();
            int i = p.first;
            int j = p.second;
            if (isValid(i-1, j)) {
                vis[i-1][j] = true;
                q.push(make_pair(i-1, j));
            }
            if (isValid(i+1, j)) {
                vis[i+1][j] = true;
                q.push(make_pair(i+1, j));
            }
            if (isValid(i, j-1)) {
                vis[i][j-1] = true;
                q.push(make_pair(i, j-1));
            }
            if (isValid(i, j+1)) {
                vis[i][j+1] = true;
                q.push(make_pair(i, j+1));
            }            
        }
        
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (!vis[i][j])
                    board[i][j] = 'X';
    }
private:
    int n, m;
    bool **vis;
    bool isValid(int i, int j) {
        if (i < 0) return false;
        if (j < 0) return false;
        if (i >= n) return false;
        if (j >= m) return false;
        return !vis[i][j];
    }
};