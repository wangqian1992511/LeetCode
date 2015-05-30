class Solution {
public:
    string shortestPalindrome(string s) {
        int n = s.size();
        string t = s;
        reverse(t.begin(), t.end());
        
        if (s == t)
            return s;
        
        int *pi = new int [n];
        pi[0] = 0;
        for (int i = 1, j = 0; i < n; i++) {
            pi[i] = j;
            while ((j > 0) && (s[j] != t[i]))
                j = pi[j];
            if (s[j] == t[i])
                j++;
        }
        
        return t + s.substr(pi[n-1] + 1, n - 1 - pi[n-1]);
    }
};
