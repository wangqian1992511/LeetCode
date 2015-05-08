class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        sort(S.begin(), S.end());
        vector<vector<int>> ans;
        vector<int> tmp;
        dfs(S, S.size(), 0, tmp, ans);
        return ans;
    }
private:
    void dfs(vector<int> &S, int n, int i, vector<int> &tmp, vector<vector<int>> &ans) {
        if (i == n) {
            ans.push_back(tmp);
            return;
        }
        dfs(S, n, i+1, tmp, ans);
        tmp.push_back(S[i]);
        dfs(S, n, i+1, tmp, ans);
        tmp.pop_back();
    }
};