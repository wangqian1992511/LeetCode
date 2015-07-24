class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        if ((n == 0) || (k > n))
            return ans;
        dfs(n, k, 1);
        return ans;
    }
private:
    vector<vector<int>> ans;
    vector<int>  now;
    void dfs(int n, int k, int st) {
        int m = now.size();
        if (m == k) 
            ans.push_back(now);
        else {
            int lmt = m + n - k + 1;
            for (int i = st; i <= lmt; i++) {
                now.push_back(i);
                dfs(n, k, i + 1);
                now.pop_back();
            }
        }
    }
};