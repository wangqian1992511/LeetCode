class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        rmn = n;
        dfs(1, k);
        return ans;
    }
private:
    vector<vector<int>> ans;
    vector<int> now;
    int rmn;
    void dfs(int t, int k) {
        if (!k && !rmn)
            ans.push_back(now);
        else if (!k || (rmn < t))
            return;
        else
            for (int i = t; i < 10; i++) {
                now.push_back(i);
                rmn -= i;
                dfs(i + 1, k - 1);
                now.pop_back();
                rmn += i;
            }
    }
};
