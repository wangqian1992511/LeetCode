class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
            return false;
        
        int t = x, c= 0;
        while (t > 0) {
            c++;
            t /= 10;
        }
        
        t = 0;
        for (int i = 0; i < (c >> 1); i++) {
            t *= 10;
            t += x % 10;
            x /= 10;
        }
        
        if (c & 1)
            x /= 10;
            
        return x == t;
    }
};