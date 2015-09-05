class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        int n = citations.size(), ans = 0;
        for (int i = n - 1; (i >= 0) && (citations[i] > ans); i--) ans++;
        return ans;
    }
};