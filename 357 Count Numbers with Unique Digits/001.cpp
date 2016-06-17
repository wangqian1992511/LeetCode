class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        int tmp = 9, ans = n ? 10 : 1;
        for (int i = 1; i < n; i++) {
            tmp *= (10 - i);
            ans += tmp;
        }
        return ans;
    }
};
