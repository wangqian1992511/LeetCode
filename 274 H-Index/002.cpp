class Solution {
public:
    int hIndex(vector<int>& citations) {
        int l = 0, r = citations.size(), n = citations.size();
        while (l < r) {
            int m = (l + r + 1) >> 1, t = 0;
            for (int i = 0; i < n; i++)
                if (citations[i] >= m)
                    t++;
            if (t < m)
                r = m - 1;
            else
                l = m;
        }
        return l;
    }
};