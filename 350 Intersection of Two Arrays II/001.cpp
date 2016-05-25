class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int p = 0, q = 0;
        int n = nums1.size(), m = nums2.size();
        vector<int> ans;
        while ((p < n) && (q < m)) {
            if (nums1[p] == nums2[q]) {
                ans.push_back(nums1[p]);
                p++;
                q++;
            }
            else if (nums1[p] < nums2[q])
                p++;
            else
                q++;
        }
        return ans;
    }
};
