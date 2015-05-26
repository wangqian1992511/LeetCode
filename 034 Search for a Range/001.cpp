class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        return helper(nums, 0, nums.size() - 1, target);
    }
private:
    vector<int> helper(vector<int>& nums, int st, int en, int target) {
        vector<int> ans;
        if (st > en) {
            ans.push_back(-1);
            ans.push_back(-1);
            return ans;
        }
        if ((nums[st] == target) && (nums[en] == target)) {
            ans.push_back(st);
            ans.push_back(en);
            return ans;
        }
        int l = st, r = en;
        while (l <= r) {
            int m = (l + r) >> 1;
            if (nums[m] < target)
                l = m + 1;
            else if (nums[m] > target)
                r = m - 1;
            else {
                vector<int> a = helper(nums, l, m - 1, target);
                vector<int> b = helper(nums, m + 1, r, target);
                if (a[0] != -1)
                    ans.push_back(a[0]);
                else
                    ans.push_back(m);
                if (b[1] != -1)
                    ans.push_back(b[1]);
                else
                    ans.push_back(m);
                return ans;
            }
        }
        ans.push_back(-1);
        ans.push_back(-1);
        return ans;
    }
};

