class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        int n = costs.size();
        if (!n) return 0;
        int k = costs[0].size();
        if (!k) return 0;
        int va = 0, vb = 0, idx = 0;
        for (int i = 0; i < n; i++) {
            int vaT = INT_MAX, vbT = INT_MAX, idxT = 0;
            for (int j = 0; j < k; j++) {
                int v;
                if (j != idx)
                    v = costs[i][j] + va;
                else
                    v = costs[i][j] + vb;
                if (v < vaT) {
                    vbT = vaT;
                    vaT = v;
                    idxT = j;
                }
                else if (v < vbT)
                    vbT = v;
            }
            va = vaT;
            vb = vbT;
            idx = idxT;
        }
        return va;
    }
};