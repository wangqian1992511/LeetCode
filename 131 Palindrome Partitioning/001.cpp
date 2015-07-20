class Solution {
public:
    vector<vector<string>> partition(string s) {
        this->s = s;
        n = s.size();
        build();
        dfs(0);
        return ans;
    }
private:
    vector<vector<string>> ans;
    vector<string> tmp;
    bool **f;
    string s;
    int n;
    void build() {
        f = new bool* [n];
        for (int i = 0; i < n; i++) {
            f[i] = new bool [n];
            f[i][i] = true;
            f[i][i+1] = (i != n-1) && (s[i] == s[i+1]);
        }
        for (int len = 3; len <= n; len++)
            for (int i = 0; i <= n - len; i++)
                f[i][i+len-1] = f[i+1][i+len-2] && (s[i] == s[i+len-1]);
    }
    void dfs(int st) {
        if (st == n) 
            ans.push_back(tmp);
        else
            for (int en = st; en < n; en++) 
                if (f[st][en]) {
                    tmp.push_back(s.substr(st, en - st + 1));
                    dfs(en + 1);
                    tmp.pop_back();
                }
    }
};