class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num < 0) return false;
        double x = sqrt(num);
        return int(x) * int(x) == num;
    }
};
