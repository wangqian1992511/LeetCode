class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s (nums.begin(), nums.end());
        int ans = 0;
        while (!s.empty()) {
            int k = *(s.begin());
            int t = 1;
            s.erase(k);
            int i = k+1;
            while (s.find(i) != s.end()) {
                s.erase(i);
                i++;
                t++;
            }
            i = k - 1;
            while (s.find(i) != s.end()) {
                s.erase(i);
                i--;
                t++;
            }     
            ans = max(ans, t);
        }
        return ans;
    }
};