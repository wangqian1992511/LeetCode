class Solution {
public:
    int maximumGap(vector<int> &num) {
        int n = num.size();
        if (n < 2) return 0;
        
        int maxN = INT_MIN, minN = INT_MAX;
        for (int i = 0; i < n; i++) {
            maxN = max(maxN, num[i]);
            minN = min(minN, num[i]);
        }
        double dist = (maxN - minN + 1e-10) / (n - 1);
        
        vector<vector<int>> bucket (n);
        for (int i = 0; i < n; i++) {
            int t = (num[i] - minN) / dist;
            if (bucket[t].empty()) {
                bucket[t].push_back(num[i]);
                bucket[t].push_back(num[i]);
            }
            else {
                bucket[t][0] = min(bucket[t][0], num[i]);
                bucket[t][1] = max(bucket[t][1], num[i]);
            }
        }
        
        int ans = bucket[0][1] - bucket[0][0], p = 0;
        for (int i = 1; i < n; i++) 
            if (!bucket[i].empty()) {
                ans = max(ans, bucket[i][0] - bucket[p][1]);
                p = i;
            }
        return ans;
    }
};