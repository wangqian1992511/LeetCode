class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        int n = S.size();
        sort(S.begin(), S.end());
        vector<int> a, c;
        rebuild(S, a, c, n);
        vector<vector<int>> ans;
        vector<int> tmp;
        dfs(a, c, a.size(), 0, tmp, ans);
        return ans;
    }
private: 
    void rebuild(vector<int> &S, vector<int> &a, vector<int> &c, int n) {
        if (n) {
            a.push_back(S[0]);
            c.push_back(1);
            int k = 0;
            for (int i = 1; i < n; i++)
                if (S[i] == a[k])
                    c[k]++;
                else {
                    a.push_back(S[i]);
                    c.push_back(1);
                    k++;
                }
        }
    }
    void dfs(vector<int> &a, vector<int> &c, int n, int i, vector<int> &tmp, vector<vector<int>> &ans) {
        if (i == n) {
            ans.push_back(tmp);
            return;
        }
        dfs(a, c, n, i+1, tmp, ans);
        for (int j = 0; j < c[i]; j++) {
            tmp.push_back(a[i]);
            dfs(a, c, n, i+1, tmp, ans);
        }
        for (int j = 0; j < c[i]; j++)
            tmp.pop_back();
    }    
};