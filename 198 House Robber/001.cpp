class Solution {
public:
    int rob(vector<int> &num) {
        int n = num.size();
        if (!n) return 0;
        int a = 0, b = 0, t;
        for (int i = 0; i < n; i++) { 
            t = b;
            b = max(a + num[i], b);
            a = t;
        }
        return b;
    }
};