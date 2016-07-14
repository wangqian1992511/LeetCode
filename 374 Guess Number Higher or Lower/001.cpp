// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        int l = 1, r = n;
        while (l < r) {
            int m = l + (r - l) / 2;
            if (guess(m) == -1)
                r = m - 1;
            else if (guess(m) == 1)
                l = m + 1;
            else
                return m;
        }
        return l;
    }
};
