class Solution {
public:
    int majorityElement(vector<int> &num) {
        int n = num.size();
        int max = 0, ans;
        unordered_map<int, int> hash;
        for (int i = 0; i < n; i++) {
            if (hash.find(num[i]) == hash.end()) 
                hash[num[i]] = 1;
            else 
                hash[num[i]]++;
            if (hash[num[i]] > max) {
                max = hash[num[i]];
                ans = num[i];
            }
        }
        return ans;
    }
};