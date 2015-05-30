class Solution {
public:
    string shortestPalindrome(string s) {
        int n = s.size();
        int m = 2 * n + 3;
        string t (m, '#');
        t[0] = '!';
        for (int i = 0; i < n; i++) 
            t[2 * (i + 1)] =  s[i];
        t[m-1] = '@';
        
        int *p = new int [m];
        fill(p, p + m, 1);
        int maxD = 0, id = 0;
        for (int i = 1; i < m - 1; i++) {
            if (maxD > i) 
                p[i] = min(p[2 * id - i], maxD - i);

            while (t[i + p[i]] == t[i - p[i]])
                p[i]++;
                
            if (i + p[i] > maxD) {
                maxD = i + p[i];
                id = i;
            }
        }
        
		int now = 1;
		for (int i = m - 1; i > 0; i--)
			if (i == p[i]) {
				now = i;
				break;			
			}

        int maxP = (now + p[now] - 4) >> 1;
        string r = s.substr(maxP + 1, n - maxP);
        reverse(r.begin(), r.end());
        return r + s;
    }
};
