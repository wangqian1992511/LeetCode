class Solution {
public:
    int romanToInt(string s) {
        int ans = 0, pre = 0, now;
        int n = s.size();
        for (int i = n-1; i >= 0; i--) {
            now = romanChToInt(s[i]);
            if (now < pre) 
                ans -= now;
            else
                ans += now;
            pre = now;
        }
        return ans;
    }
private:
    int romanChToInt(char ch) {
        switch (ch) {
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
        }
    }
};