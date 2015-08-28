class Solution {
public:
    vector<string> generatePalindromes(string s) {
        n = s.size();
        for (int i = 0; i < n; i++) 
            cnt[s[i]]++;
        
        odd = 0;
        for (auto it = cnt.begin(); it != cnt.end(); it++) {
            if (it->second & 1) {
                mid = it->first;
                odd++;
            }
            it->second >>= 1;
        }
        
        if ((odd == 0) || (odd == 1)) 
            dfs(0);
        
        return ans;
    }
private:
    vector<string> ans;
    unordered_map<char, int> cnt;
    string left;
    int n, odd;
    char mid;
    void dfs(int d) {
        if (d != n / 2) {
            for (auto it = cnt.begin(); it != cnt.end(); it++) 
                if (it->second) {
                    it->second--;
                    left.push_back(it->first);
                    dfs(d + 1);
                    left.pop_back();
                    it->second++;
                }
        }
        else {
            string right (left);
            reverse(right.begin(), right.end());
            if (odd == 0)
                ans.push_back(left + right);
            else
                ans.push_back(left + mid + right);
        }
    }
};