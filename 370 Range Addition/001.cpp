class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        int* inc = new int [length];
        memset(inc, 0, length * sizeof(int));

        for (auto it: updates) {
            int st = it[0];
            int en = it[1];
            int v = it[2];
            inc[st] += v;
            if (en + 1 != length)
                inc[en + 1] -= v;
        }

        vector<int> ans;
        int tmp = 0;
        for (int i = 0; i < length; i++) {
            tmp += inc[i];
            ans.push_back(tmp);
        }
        return ans;
    }
};
