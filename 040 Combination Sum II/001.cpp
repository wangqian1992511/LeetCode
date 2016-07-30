class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
        int last = -1;
        sort(candidates.begin(), candidates.end());
        for (auto it: candidates)
            if (last == it)
                cnt.back()++;
            else {
                last = it;
                list.push_back(it);
                cnt.push_back(1);
            }
        rmn = target;
        dfs(list.size() - 1);
        return ans;
    }
private:
    vector<vector<int>> ans;
    vector<int> now, list, cnt;
    int rmn;
    void dfs(int p) {
        for (int i = p; i >= 0; i--) {
            int x = list[i], c = cnt[i];
            for (int j = 1; j <= c; j++) {
                now.push_back(x);
                rmn -= x;
                if (rmn > 0)
                    dfs(i - 1);
                else if (rmn == 0)
                    ans.push_back(now);
            }
            for (int j = 1; j <= c; j++) {
                now.pop_back();
                rmn += x;
            }
        }
    }
};
