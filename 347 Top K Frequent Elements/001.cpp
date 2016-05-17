class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> valToCnt;
        for (auto it: nums)
            valToCnt[it]++;

        map<int, vector<int>> cntToVal;
        for (auto it: valToCnt)
            cntToVal[-it.second].push_back(it.first);

        vector<int> ans;
        for (auto it: cntToVal) {
            for (auto itB: it.second) {
                ans.push_back(itB);
                k--;
                if (!k) return ans;
            }
        }
        return ans;
    }
};
