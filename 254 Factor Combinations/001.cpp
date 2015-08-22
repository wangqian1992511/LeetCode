class Solution {
public:
    vector<vector<int>> getFactors(int n) {
        int t = sqrt(n + 0.001);
        for (int i = 2; i <= t; i++)
            if (n % i == 0)
                fac.push_back(i);
        dfs(n, 0);
        return ans;
    }
private:
    vector<int> tmp;
    vector<vector<int>> ans;
    vector<int> fac;
    void dfs(int x, int i) {
        int t = sqrt(x + 0.001);
        for (; (i < fac.size()) && (t >= fac[i]); i++)
            if (x % fac[i] == 0) {
                tmp.push_back(fac[i]);
                tmp.push_back(x / fac[i]);
                ans.push_back(tmp);
                tmp.pop_back();
                dfs(x / fac[i], i);
                tmp.pop_back();
            }
    }
};