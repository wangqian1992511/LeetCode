class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        int n = num.size();
        sort(num.begin(), num.end());     
        int ans = 1, now = num[0], tmp = 1;
        for (int i = 1; i < n; i++)
            if (num[i] == now) 
                continue;
            else if (num[i] == now + 1) {
                now++;
                tmp++;
            }
            else {
                ans = max(ans, tmp);
                now = num[i];
                tmp = 1;
            }
        ans = max(ans, tmp);
        return ans;
    }
};