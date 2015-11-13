class Solution {
public:
    bool validTree(int n, vector<pair<int, int>>& edges) {
        if (edges.size() != n-1) return false;
        father = new int [n];
        rank = new int [n];
        memset(rank, 0, n * sizeof(int));
        for (int i = 0; i < n; i++)
            father[i] = i;
        for (auto e = edges.begin(); e != edges.end(); e++) {
            int fu = getFather(e->first);
            int fv = getFather(e->second);
            if (fu == fv) return false;
            unionIt(fu, fv);
        }
        return true;
    }
private:
    int *father;
    int *rank;
    int getFather (int x) {
        if (father[x] != x)
            father[x] = getFather(father[x]);
        return father[x];
    }
    void unionIt(int a, int b) {
        if (rank[a] < rank[b])
            father[a] = b;
        else if (rank[b] < rank[a])
            father[b] = a;
        else {
            father[b] = a;
            rank[a]++;
        }
    }
};