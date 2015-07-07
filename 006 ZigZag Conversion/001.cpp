class Solution {
public:
    string convert(string s, int nRows) {
        int n = s.size();
        if ((nRows == 1) || (nRows == n))
            return s;
        string ans = "";
        int t = 2 * (nRows - 1);
        for (int i = 0; i < nRows; i++) {
            int p = i;
            if ((i == 0) || (i == nRows - 1)) {
                while (p < n) {
                    ans += s[p];
                    p += t;
                }
            }
            else {
                int d = 2 * (nRows - 1 - i);
                while (p < n) {
                    ans += s[p];
                    p += d;
                    d = t - d;
                }
            }
        }
        return ans;
    }
};