class Solution {
public:
    int myAtoi(string str) {
        int p = 0, n = str.size();
        while ((p < n) && (str[p] == ' ')) p++;
        
        bool pos = true;
        if (p < n) {
            if (str[p] == '-') {
                pos = false;
                p++;
            }
            else if (str[p] == '+') {
                p++;
            }
        }
        
        int64_t ans = 0;
        int i = 0;
        while ((p < n) && (i < 11) && (str[p] >= '0') && (str[p] <= '9')) {
            ans *= 10;
            ans += str[p] - '0';
            p++;
            i++;
        }
        
        if (!pos) ans = -ans;
        
        if (ans > INT_MAX) return INT_MAX;
        if (ans < INT_MIN) return INT_MIN;
        return int(ans);
    }
};