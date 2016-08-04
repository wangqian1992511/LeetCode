struct compT {
    bool operator ()(pair<int, int> &a, pair<int, int> &b) {
        if (a.first < b.first) return true;
        if (a.first > b.first) return false;
        return a.second > b.second;
    }
};

class Solution {
public:
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), compT());
        return lengthOfLIS(envelopes);
    }
private:
    int lengthOfLIS(vector<pair<int, int>>& nums) {
        int n = nums.size();
        int *lenMin = new int [n + 1];
        fill(lenMin, lenMin + n + 1, INT_MAX);

        int ans = 0;
        for (auto it: nums) {
            int l = 1, r = n;
            while (l != r) {
                int m = l + (r - l) / 2;
                if (lenMin[m] < it.second)
                    l = m + 1;
                else
                    r = m;
            }
            lenMin[l] = it.second;
            ans = max(l, ans);
        }
        return ans;
    }
};
