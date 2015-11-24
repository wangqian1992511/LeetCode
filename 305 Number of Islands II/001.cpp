class Solution {
public:
    vector<int> numIslands2(int len, int wid, vector<pair<int, int>>& positions) {
        int n = len * wid;
        father = new int [n];
        rank = new int [n];
        fill(father, father + n, -1);
        fill(rank, rank + n, 0);
        int dx[] = {0, 0, 1, -1};
        int dy[] = {1, -1, 0, 0};
        int tot = 0;
        vector<int> ans;
        for (auto it = positions.begin(); it != positions.end(); it++) {
            int x = it->first;
            int y = it->second;
            int h = x * wid + y;
            father[h] = h;
            rank[h] = 0;
            tot++;
            for (int i = 0; i < 4; i++) {
                int xp = x + dx[i];
                int yp = y + dy[i];
                int hp = xp * wid + yp;
                if (isValid(xp, len, yp, wid, hp) && unionIt(h, hp))
                    tot--;
            }
            ans.push_back(tot);
        }
        return ans;
    }
private:
    int *father, *rank;
    bool isValid(int x, int len, int y, int wid, int hp) {
        if (x < 0) return false;
        if (y < 0) return false;
        if (x >= len) return false;
        if (y >= wid) return false;
        return father[hp] >= 0;
    }
    int getFather (int x) {
        if (father[x] != x)
            father[x] = getFather(father[x]);
        return father[x];
    }
    bool unionIt(int a, int b) {
        int fa = getFather(a);
        int fb = getFather(b);
        if (fa == fb)
            return false;
        if (rank[fa] < rank[fb])
            father[fa] = fb;
        else if (rank[fb] < rank[fa])
            father[fb] = fa;
        else {
            father[fb] = fa;
            rank[fa]++;
        }
        return true;
    }
};