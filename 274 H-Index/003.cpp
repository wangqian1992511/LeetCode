class Solution {
public:
    int hIndex(vector<int>& citations) {
        unordered_map<int, int> cnt;
        int n = citations.size();
        for (int i = 0; i < n; i++)
            if (citations[i] >= n)
                cnt[n]++;
            else
                cnt[citations[i]]++;
        int tot = 0;
        for (int i = n; i > 0; i--) {
            tot += cnt[i];
            if (tot >= i)
                return i;
        }
        return 0;
    }
};