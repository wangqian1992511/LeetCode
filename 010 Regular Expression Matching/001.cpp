class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        bool **f = new bool* [n+1];
        for (int i = 0; i <= n; i++) {
            f[i] = new bool [m+1];
            fill(f[i], f[i] + m + 1, false);
        }
        f[n][m] = true;
        if (n) f[n-1][m-1] = isMatch(s[n-1], p[m-1]);
        for (int j = m-2; j >= 0; j--) {
            f[n][j] = f[n][j+2] && (p[j+1] == '*');
            for (int i = n-1; i >= 0; i--) {
                f[i][j] = f[i][j+2] && (p[j+1] == '*');
                if (!f[i][j] && isMatch(s[i], p[j]))
                    f[i][j] = f[i+1][j+1] || f[i+1][j] && (p[j+1] == '*');
            }
        }
        return f[0][0];
    }
private:
    inline bool isMatch(char a, char b) {
        return (a ==  b) || (b == '.');
    }
};