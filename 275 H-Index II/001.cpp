class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        citations.push_back(INT_MAX);
        int l = 0, r = n;
        while (l < r) {
            int m = (l + r + 1) >> 1;
            if (citations[n - m] >= m)
                l = m;
            else
                r = m - 1;
        }
        return l;
    }
};