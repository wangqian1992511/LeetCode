class Solution {
public:
    int maximumGap(vector<int> &num) {
        int n = num.size();
        if (n < 2) return 0;
        sort(num.begin(), num.end());
        int ans = 0;
        for (int i = 1; i < n; i++) 
            ans = max(ans, num[i] - num[i-1]);
        return ans;
    }
};