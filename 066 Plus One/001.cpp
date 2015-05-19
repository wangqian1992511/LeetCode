class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        vector<int> ans;
        int n = digits.size();
        if (!n) return ans;
        for (int i = n-1; i >= 0; i--)
            ans.push_back(digits[i]);
        ans[0]++;
        for (int i = 0; i < n - 1; i++) {
            ans[i + 1] += (ans[i] / 10);
            ans[i] %= 10;
        }
        if (ans[n-1] >= 10) {
            ans[n-1] %= 10;
            ans.push_back(1);
            n++;
        }
        for (int i = 0; i < n / 2; i++) 
            swap(ans[i], ans[n-i-1]);
        return ans;
    }
};