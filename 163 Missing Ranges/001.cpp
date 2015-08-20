class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        while (n && (nums[n-1] > upper))
            n--;
        vector<string> ans;
        for (int i = 0; i < n; i++) 
            if (lower == nums[i])
                lower++;
            else if (lower < nums[i]) {
                ans.push_back(build(lower, nums[i] - 1));
                lower = nums[i] + 1;
            }
        if (lower <= upper)
            ans.push_back(build(lower, upper));
        return ans;
    }
private:
    string build(int st, int en) {
        if (st != en) 
            return to_string(st) + "->" + to_string(en);
        else
            return to_string(st);
    }
};