class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        int n = strs.size();
        if (!n) return "";
        
        int j = 0;
        while (j < strs[0].size()) {
            for (int i = 1; i < n; i++) 
                if ((j == strs[i].size()) || (strs[i][j] != strs[0][j]))
                    return strs[0].substr(0, j);
            j++;
        }
        return strs[0].substr(0, j);
    }
};