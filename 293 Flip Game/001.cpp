class Solution {
public:
    vector<string> generatePossibleNextMoves(string s) {
        int n = s.size();
        vector<string> ans;
        for (int i = 1; i < n; i++)
            if (s[i-1] == '+' && s[i] == '+') 
                ans.push_back(s.substr(0, i-1) + "--" + s.substr(i + 1, n - i - 1));
        return ans;
    }
};
