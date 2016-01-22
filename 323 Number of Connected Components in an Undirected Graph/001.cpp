class Solution {
public:
    int countComponents(int n, vector<pair<int, int>>& edges) {
        father = new int [n];
        rank = new int [n];
        fill(rank, rank + n, 0);
        for (int i = 0; i < n; i++)
            father[i] = i;
        for (auto it: edges) {
            int x = it.first;
            int y = it.second;
            if (unionIt(x, y))
                n--;
        }
        return n;
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
