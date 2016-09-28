class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
        int sum = 0, tmp = 0, rep = 0;
        for (auto it: A) {
            sum += it;
            tmp += rep * it;
            rep++;
        }

        int ans = tmp, n = A.size();
        for (auto it: A) {
            tmp = tmp - sum + n * it;
            ans = max(ans, tmp);
        }

        return ans;
    }
};
