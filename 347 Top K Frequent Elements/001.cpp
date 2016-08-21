class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> cnt;
        for (auto it: nums)
            cnt[it]++;

        int n = nums.size();
        vector<int> *bucket = new vector<int> [n + 1];
        for (auto it: cnt)
            bucket[it.second].push_back(it.first);

        vector<int> ans;
        for (int i = n; i > 0; i--)
            for (auto it: bucket[i])
                if (k--)
                    ans.push_back(it);
                else
                    return ans;
        return ans;
    }
};
