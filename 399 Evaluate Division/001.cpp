class Solution {
public:
    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
        unordered_set<string> s;
        unordered_set<string> zero;
        unordered_map<string, unordered_map<string, double>> edge;

        vector<double>::iterator x = values.begin();
        for (auto it: equations) {
            s.insert(it.first);
            s.insert(it.second);
            edge[it.first][it.first] = 1;
            edge[it.second][it.second] = 1;
            edge[it.first][it.second] = *x;
            if (isNonZero(*x))
                edge[it.second][it.first] = 1 / *x;
            else
                zero.insert(it.first);
            x++;
        }

        for (auto k: s)
            for (auto i: s)
                for (auto j: s)
                    if (edge.count(i) && edge[i].count(k) && edge.count(k) && edge[k].count(j))
                        edge[i][j] = edge[i][k] * edge[k][j];

        vector<double> ans;
        for (auto it: queries)
            if (zero.count(it.second))
                ans.push_back(-1);
            else if (edge.count(it.first) && edge[it.first].count(it.second))
                ans.push_back(edge[it.first][it.second]);
            else
                ans.push_back(-1);
        return ans;
    }
private:
    bool isNonZero(double x) {
        return (x > 1e-10) || (x < -1e-10);
    }
};
