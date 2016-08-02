class Solution {
public:
    bool isReflected(vector<pair<int, int>>& points) {
        unordered_map<int, unordered_set<int>> ptSet;
        unordered_map<int, int> minV, maxV;
        int doubleMid;
        for (auto it: points) {
            ptSet[it.second].insert(it.first);
            if (!minV.count(it.second) || (minV[it.second] > it.first))
                minV[it.second] = it.first;
            if (!maxV.count(it.second) || (maxV[it.second] < it.first))
                maxV[it.second] = it.first;
            doubleMid = minV[it.second] + maxV[it.second];
        }
        for (auto it: ptSet) {
            int y = it.first;
            unordered_set<int> &s = it.second;
            for (auto x: s)
                if (!s.count(doubleMid - x))
                    return false;
        }
        return true;
    }
};
