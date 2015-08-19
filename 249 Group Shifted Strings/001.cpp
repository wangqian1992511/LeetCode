class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        sort(strings.begin(), strings.end());
        int n = strings.size();
        for (int i = 0; i < n; i++) {
            string x = calc(strings[i]);
            hash[x].push_back(strings[i]);
        }
        vector<vector<string>> ans;
        for (auto it = hash.begin(); it != hash.end(); it++)
            ans.push_back(it->second);
        return ans;
    }
private:
    unordered_map<string, vector<string>> hash;
    string calc(string s) {
        string ans = "";
        int n = s.size();
        int d = s[0] - 'a';
        for (int i = 0; i < n; i++) {
            char ch = s[i] - d;
            if (ch < 'a') ch += 26;
            ans += ch;
        }
        return ans;
    }
};