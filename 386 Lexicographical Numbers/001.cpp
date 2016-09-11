class Solution {
public:
    vector<int> lexicalOrder(int n) {
        this->n = n;
        dfs(0);
        return ans;
    }
private:
    vector<int> ans;
    int n;
    void dfs(int x) {
        for (int i = x; i <= x + 9; i++) {
            if (!i)
                continue;
            if (i <= n) {
                ans.push_back(i);
                dfs(i * 10);
            }
        }
    }
};
