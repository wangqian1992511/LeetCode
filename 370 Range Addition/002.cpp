class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        map<int, int> inc;

        for (auto it: updates) {
            int st = it[0];
            int en = it[1];
            int v = it[2];
            inc[st] += v;
            if (en + 1 != length)
                inc[en + 1] -= v;
        }

        int p = 0, tmp = 0;
        inc[length] = 1;
        vector<int> ans;
        for (auto it: inc) {
            for (; p < it.first; p++)
                ans.push_back(tmp);
            tmp += it.second;
        }
        return ans;
    }
};
