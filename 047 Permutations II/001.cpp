class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        vis = new bool [nums.size()];
        memset(vis, 0, sizeof(vis));
        dfs(0, nums.size(), nums);
        return ans;
    }
private:
    bool *vis;
    vector<int> tmp;
    vector<vector<int>> ans;
    void dfs(int d, int n, vector<int> &nums) {
        if (d== n) {
            ans.push_back(tmp);
            return;
        }
        for (int i = 0; i < n; i++)
            if (isValid(i, nums)) {
                vis[i] = true;
                tmp.push_back(nums[i]);
                dfs(d + 1, n, nums);
                tmp.pop_back();
                vis[i] = false;
            }
    }
    bool isValid(int i, vector<int> &nums) {
        if (vis[i]) return false;
        if (!i) return true;
        if (nums[i] != nums[i - 1]) return true;
        return vis[i - 1];
    }
};