class Solution {
public:
    bool validTree(int n, vector<pair<int, int>>& edges) {
        if (edges.size() != n-1) return false;
        for (int i = 0; i < n; i++) father.push_back(i);
        for (auto e = edges.begin(); e != edges.end(); e++) {
            int u = e->first;
            int v = e->second;
            int fu = getFather(u);
            int fv = getFather(v);
            if (fu == fv) return false;
            unionIt(fu, fv);
        }
        return true;
    }
private:
    vector<int> father;
    int getFather (int x) {
        if (father[x] == x) return x;
        int f = getFather(father[x]);
        father[x] = f;
        return f;
    }
    void unionIt(int a, int b) {
        father[a] = b;
    }
};