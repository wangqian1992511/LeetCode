class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        int m = matrix.size();
        if (m == 0) 
            return false;
        int n = matrix[0].size();
        if (n == 0) 
            return false;
        
        int l = 0, r = m-1;
        while (l <= r) {
            int mid = (l + r) >> 1;
            int k = isIn(target, matrix, mid, n);
            if (k == -1)
                r = mid - 1;
            else if (k == 1)
                l = mid + 1;
            else {
                int k = mid, l = 0, r = n-1;
                while (l <= r) {
                    int mid = (l + r) >> 1;
                    if (matrix[k][mid] == target)
                        return true;
                    else if (matrix[k][mid] > target)
                        r = mid - 1;
                    else
                        l = mid + 1;
                }
                return false;
            }
        }

        return false;
    }
private:
    int isIn(int x, vector<vector<int> > &matrix, int m, int n) {
        if (matrix[m][0] > x)
            return -1;
        if (matrix[m][n-1] < x)
            return 1;
        return 0;
    }
};
