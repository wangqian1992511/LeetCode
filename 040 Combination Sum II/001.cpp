class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
        vector<vector<int>> ans;
        int n = candidates.size();
        if (!n) return ans;
        sort(candidates.begin(), candidates.end());
        vector<int> list, cnt;
        int tmp = 1;
        list.push_back(candidates[0]);
        for (int i = 1; i < n; i++)
            if (candidates[i] != candidates[i-1]) {
                cnt.push_back(tmp);
                list.push_back(candidates[i]);
                tmp = 1;
            }
            else
                tmp++;
        cnt.push_back(tmp);
        vector<int> now;
        dfs(list, cnt, list.size()-1, now, ans, target);
        return ans;
    }
private:
    void dfs(vector<int> &list, vector<int> &cnt, int p, vector<int> &now, vector<vector<int>> &ans, int rmn) {
        for (int i = p; i >= 0; i--) {
            int j = 0;
            while ((list[i] <= rmn) && (j < cnt[i])) {
                rmn -= list[i];
                now.push_back(list[i]);
                if (rmn)
                    dfs(list, cnt, i - 1, now, ans, rmn);
                else {
                    vector<int> put;
                    for (int k = now.size()-1; k >= 0; k--)
                        put.push_back(now[k]);
                    ans.push_back(put);
                }
                j++;
            }
            while (j) {
                rmn += list[i];
                now.pop_back();
                j--;
            }
        }
    }
};