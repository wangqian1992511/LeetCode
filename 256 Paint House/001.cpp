class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        int a = 0, b = 0, c = 0;
        int n = costs.size();
        for (int i = 0; i < n; i++) {
            int na = min(b, c) + costs[i][0];
            int nb = min(a, c) + costs[i][1];
            int nc = min(a, b) + costs[i][2];
            a = na;
            b = nb; 
            c = nc;
        }
        return min(a, min(b, c));
    }
};