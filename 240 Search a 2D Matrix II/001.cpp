class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        this->target = target;
        int n = matrix.size();
        if (!n) return false;
        int m = matrix[0].size();
        if (!m) return false;
        return searchIt(matrix, 0, 0, n-1, m-1);
    }
private:
    int target;
    bool searchIt(vector<vector<int>>& matrix, int nL, int mL, int nR, int mR) {
        if (nL > nR) return false;
        if (mL > mR) return false;
        if (matrix[nL][mL] > target) return false;
        if (matrix[nR][mR] < target) return false;
        if ((nL == nR) && (mL == mR)) return matrix[nL][mL] == target;
        int nM = (nL + nR) >> 1;
        int mM = (mL + mR) >> 1;
        if (searchIt(matrix, nL, mL, nM, mM)) return true;
        if (searchIt(matrix, nM + 1, mL, nR, mM)) return true;
        if (searchIt(matrix, nL, mM + 1, nM, mR)) return true;
        if (searchIt(matrix, nM + 1, mM + 1, nR, mR)) return true;
        return false;
    }
};