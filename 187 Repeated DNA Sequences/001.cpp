class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> ans;
        bool vis[0xfffff];
        bool put[0xfffff];
        memset(vis, 0, sizeof(vis));
        memset(put, 0, sizeof(put));
        int n = s.size();
        int k = calc(s.substr(0, 9));
        for (int i = 0; i <= n - 10; i++) {
            update(k, s[i + 9]);
            if (!vis[k])
                vis[k] = true;
            else if (!put[k]) {
                put[k] = true;
                ans.push_back(s.substr(i, 10));
            }
        }
        return ans;
    }
private:
    int calc(string str) {
        int ans = 0;
        int n = str.size();
        for (int i = 0; i < n; i++)
            update(ans, str[i]);
        return ans;
    }
    void update(int &k, char ch) {
        k <<= 2;
        k &= 0xfffff;
        switch (ch) {
            case 'C': k++; break;
            case 'G': k += 2; break;
            case 'T': k += 3; break;
        }
    }
};