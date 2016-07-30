class Solution {
public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
        sort(candidates.begin(), candidates.end());
        candidates.erase(unique(candidates.begin(), candidates.end()), candidates.end());
        list = candidates;
        rmn = target;
        dfs(list.size() - 1);
        return ans;
    }
private:
    vector<vector<int>> ans;
    vector<int> now, list;
    int rmn;
    void dfs(int p) {
        for (int i = p; i >= 0; i--) {
            int x = list[i];
            now.push_back(x);
            rmn -= x;
            if (rmn > 0)
                dfs(i);
            else if (rmn == 0)
                ans.push_back(now);
            now.pop_back();
            rmn += x;
        }
    }
};
