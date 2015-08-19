class Solution {
public:
    int nthUglyNumber(int n) {
        set<int64_t> s;
        s.emplace(1);
        int64_t ans = 0;
        for (int i = 0; i < n; i++) {
            auto minV = s.begin();
            ans = *minV;
            s.emplace(ans * 2);
            if (ans % 2 == 0)
                s.emplace(ans / 2 * 3);
            if (ans % 3 == 0)
                s.emplace(ans / 3 * 5);
            s.erase(ans);
        }
        return ans;
    }
};