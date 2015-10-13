class Solution {
public:
    vector<string> addOperators(string num, int64_t target) {
        this->len = num.size();
        this->num = num;
        this->target = target;
        dfs(0, 0, "", 0, true, true);
        return ans;
    }
private:
    vector<string> ans;
    string num;
    int len;
    int64_t target;
    void dfs(int idx, int64_t val, string tmpStr, int64_t preCand, bool isPrePlus, bool isFirst) {
        if (idx == len) {
            if (val == target)
                ans.push_back(tmpStr);
            return;
        }
        for (int i = idx + 1; i <= len; i++) {
            string str = num.substr(idx, i - idx);
            int64_t cand = stol(str);
            if (to_string(cand) != str) break;
            if (!isFirst) {
                dfs(i, val + cand, tmpStr + '+' + str, cand, true, false);
                dfs(i, val - cand, tmpStr + '-' + str, cand, false, false);
                cand *= preCand;
                if (isPrePlus)
                    dfs(i, val - preCand + cand, tmpStr + '*' + str, cand, true, false);
                else
                    dfs(i, val + preCand - cand, tmpStr + '*' + str, cand, false, false);
            }
            else
                dfs(i, val + cand, str, cand, true, false);
        }
    }
};
