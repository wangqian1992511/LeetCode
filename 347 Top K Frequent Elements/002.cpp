class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> valToCnt;
        for (auto it: nums)
            valToCnt[it]++;

        map<int, vector<int>> bucket;
        for (auto it: valToCnt)
            bucket[-it.second].push_back(it.first);

        vector<int> ans;
        for (auto it: bucket)
            for (auto itB: it.second)
                if (k--)
                    ans.push_back(itB);
                else
                    return ans;
        return ans;
    }
};
