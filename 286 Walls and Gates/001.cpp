class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        n = rooms.size();
        if (!n) return;
        m = rooms[0].size();
        if (!m) return;
        
        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (!rooms[i][j])
                    q.push({i, j});
                    
        while (!q.empty()) {
            pair<int, int> pr = q.front();
            q.pop();
            if (isValid(pr, 0, 1, rooms)) {
                rooms[pr.first][pr.second + 1] = rooms[pr.first][pr.second] + 1;
                q.push({pr.first, pr.second + 1});
            }
            if (isValid(pr, 0, -1, rooms)) {
                rooms[pr.first][pr.second - 1] = rooms[pr.first][pr.second] + 1;
                q.push({pr.first, pr.second - 1});
            }
            if (isValid(pr, 1, 0, rooms)) {
                rooms[pr.first + 1][pr.second] = rooms[pr.first][pr.second] + 1;
                q.push({pr.first + 1, pr.second});
            }
            if (isValid(pr, -1, 0, rooms)) {
                rooms[pr.first - 1][pr.second] = rooms[pr.first][pr.second] + 1;
                q.push({pr.first - 1, pr.second});
            }
        }
    }
private:
    int n, m;
    bool isValid(pair<int, int> &pr, int dx, int dy, vector<vector<int>>& rooms) {
        if (pr.first + dx < 0) return false;
        if (pr.first + dx >= n) return false;
        if (pr.second + dy < 0) return false;
        if (pr.second + dy >= m) return false;
        return rooms[pr.first + dx][pr.second + dy] == INT_MAX;
    }
};
