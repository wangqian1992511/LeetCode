class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        int idx = 0;
        unordered_map<int, int> hash;
        vector<int> ans;
        for (auto it: numbers) {
            int x = target - it;
            if (hash.count(x)) {
                ans.push_back(hash[x]);
                ans.push_back(idx);
                return ans;
            }
            hash[it] = idx++;
        }
        return ans;
    }
};
