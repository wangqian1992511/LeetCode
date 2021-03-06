class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int m = 2 * n + 3;
        string t (m, '#');
        t[0] = '!';
        for (int i = 0; i < n; i++) 
            t[2 * (i + 1)] =  s[i];
        t[m-1] = '@';
        
        int *p = new int [m];
        fill(p, p + m, 1);
        int maxD = 1, id = 0;
        for (int i = 1; i < m; i++) {
            if (maxD > i)
                p[i] = min(p[2 * id - i], maxD - i);
            while (t[i + p[i]] == t[i - p[i]])
                p[i]++;
            if (i + p[i] > maxD) {
                maxD = i + p[i];
                id = i;
            }
        }
        
        int tmp = 0, now;
        for (int i = 0; i < m; i++) 
            if (p[i] > tmp) {
                tmp = p[i];
                now = i;
            }
            
        int minP = (now - p[now]) >> 1;
        int maxP = (now + p[now] - 4) >> 1;
        return s.substr(minP, maxP - minP + 1);
    }
};
