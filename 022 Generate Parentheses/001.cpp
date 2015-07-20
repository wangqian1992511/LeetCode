class Solution {
public:
    vector<string> generateParenthesis(int n) {
        dfs(n, n, "");
        return ans;
    }
    void dfs(int l, int r, string str) {
        if (!r) 
            ans.push_back(str);
        if (l)
            dfs(l-1, r, str+"(");
        if (r && (l < r))
            dfs(l, r-1, str+")");
    }
private:
    vector<string> ans;
};