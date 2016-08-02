class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        n = matrix.size();
        int l = matrix[0][0], r = matrix[n-1][n-1];

        while (l != r) {
            int m = l + (r - l) / 2, cnt = 0;
            for (int i = 0; i < n; i++)
                cnt += search(matrix[i], m);
            if (cnt < k)
                l = m + 1;
            else
                r = m;
        }

        return l;
    }
private:
    int n;
    int search(vector<int> &list, int x) {
        int l = 0, r = n - 1;
        while (l < r) {
            int m = l + (r - l) / 2;
            if (list[m] <= x)
                l = m + 1;
            else
                r = m;
        }
        return (l == r) && (list[l] <= x) ? l + 1 : l;
    }
};
