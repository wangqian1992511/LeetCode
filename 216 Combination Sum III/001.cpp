class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        dfs(1, k, n);
        return ans;
    }
private:
    vector<vector<int> > ans;
    vector<int> tmp;
    void dfs(int t, int k, int n) {
        if (!k && !n) {
            ans.push_back(tmp);
            return;
        }
        for (int i = t; i < 10; i++) {
            tmp.push_back(i);
            dfs(i + 1, k - 1, n - i);
            tmp.pop_back();
        }
    }
};
