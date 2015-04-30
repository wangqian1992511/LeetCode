class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        int n = strs.size();
        if (!n) return "";
        int m = 0, l = 0, r = INT_MAX;
        for (int i = 0; i < n; i++)
            if (strs[i].size() < r) 
                r = strs[i].size();
            
        bool flag;    
        while (l < r) {
            flag = true;
            m = (l + r + 1) >> 1;
            for (int i = 1; i < n; i++)
                if (strs[i].substr(0, m) != strs[0].substr(0, m)) {
                    r = m - 1;
                    flag = false;
                    break;
                }
            if (flag)
                l = m;
        }
        
        return strs[0].substr(0, l);
    }
};