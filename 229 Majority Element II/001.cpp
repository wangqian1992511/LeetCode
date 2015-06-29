class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size(), p = 0;
        vector<int> ans;
        if (!n) return ans;
        for (int t = 0; t < 8; t++) {
            int x = nums[rand() % n];
            if (p && (ans[0] == x)) continue;
            int c = 0;
            for (int i = 0; i < n; i++)
                c += (nums[i] == x);
            if (c > n / 3) {
                ans.push_back(x);
                if (++p == 2) 
                    return ans;
            }
        }
        return ans;
    }
};