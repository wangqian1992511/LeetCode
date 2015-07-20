class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        if (!n) return 0;
        int *dp = new int [n+1];
        dp[n] = 1;
        dp[n-1] = (s[n-1] != '0');
        for (int i = n-2; i >= 0; i--)
            if (isValid(s[i], s[i+1]))
                dp[i] = dp[i+1] + dp[i+2];
            else if (s[i] != '0')
                dp[i] = dp[i+1];
            else
                dp[i] = 0;
        return dp[0];
    }
private:
    bool isValid(char a, char b) {
        if ((a != '1') && (a != '2')) 
            return false;
        if ((a == '2') && (b > '6'))
            return false;
        return true;
    }
};