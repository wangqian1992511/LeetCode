class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        unordered_set<int> s (nums1.begin(), nums1.end());
        for (auto it: nums2)
            if (s.find(it) != s.end()) {
                s.erase(it);
                ans.push_back(it);
            }
        return ans;
    }
};
