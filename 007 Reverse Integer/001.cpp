class Solution {
public:
    int reverse(int x) {
        while (x && !(x % 10))
            x /= 10;
        if (x == 0)
            return 0;
        else if (x < 0) {
            x = -x;
            int t = helper(x);
            int p = helper(t);
            return x == p ? -t : 0;
        }
        else {
            int t = helper(x);
            int p = helper(t);
            return x == p ? t : 0;
        }
    }
private:
    int helper(int x) {
        int t = 0;
        while (x > 0) {
            t *= 10;
            t += (x % 10);
            x /= 10;
        }   
        return t;
    }
};