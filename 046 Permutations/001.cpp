class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        n = num.size();
        vis = new bool [n];
        memset(vis, 0, sizeof(vis));
        dfs(1, num);
        return ans;
    }
private:
    vector<vector<int>> ans;
    vector<int> tmp;
    bool *vis;
    int n;
    void dfs(int i, vector<int> &num) {
        if (i > n) {
            ans.push_back(tmp);
            return;
        }
        for (int k = 0; k < n; k++)
            if (! vis[k]) {
                vis[k] = true;
                tmp.push_back(num[k]);
                dfs(i + 1, num);
                tmp.pop_back();
                vis[k] = false;
            }
    }
};