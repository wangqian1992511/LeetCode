class Solution {
public:
    int integerReplacement(int64_t n) {
        if (n == 1)
            return 0;
        if (!dep.count(n)) {
            if (n & 1) {
                dep[n] = 1 + min(integerReplacement(n + 1), integerReplacement(n - 1));
            }
            else {
                dep[n] = 1 + integerReplacement(n >> 1);
            }
        }
        return dep[n];
    }
private:
    unordered_map<int, int> dep;
};
