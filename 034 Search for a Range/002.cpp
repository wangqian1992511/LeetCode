class Solution {
public:
    vector<int> searchRange(vector<int> &A, int &target) {
        vector<int> ans;
        ans.push_back(minSearch(A, target));
        ans.push_back(maxSearch(A, target));
        return ans;
    }
private:
    int minSearch(vector<int> &A, int &key) {
        int l = 0, r = A.size() - 1;
        while (l < r) {
            int m = (l + r) >> 1;
            if (A[m] < key)
                l = m + 1;
            else if (A[m] > key)
                r = m - 1;
            else
                r = m;
        }
        if ((l == r) && (A[l] == key))
            return l;
        else
            return -1;
    }
    int maxSearch(vector<int> &A, int &key) {
        int l = 0, r = A.size() - 1;
        while (l < r) {
            int m = (l + r + 1) >> 1;
            if (A[m] < key)
                l = m + 1;
            else if (A[m] > key)
                r = m - 1;
            else
                l = m;
        }
        if ((l == r) && (A[l] == key))
            return l;
        else
            return -1;
    }    
};