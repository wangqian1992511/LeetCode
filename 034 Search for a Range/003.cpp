class Solution {
public:
    vector<int> searchRange(vector<int> &A, int &target) {
        vector<int> ans;
        pair<vector<int>::iterator, vector<int>::iterator> p = equal_range(A.begin(), A.end(), target);
        if (p.first == p.second) {
            ans.push_back(-1);
            ans.push_back(-1);
        }
        else {
            ans.push_back(distance(A.begin(), p.first));
            ans.push_back(distance(A.begin(), p.second) - 1);
        }
        return ans;
    }
};