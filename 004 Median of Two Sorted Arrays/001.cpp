class Solution {
public:
    double findMedianSortedArrays(vector<int> &A, vector<int> &B) {
        int m = A.size(), n = B.size();
        if (!n) 
            return 0.5 * (A[m >> 1] + A[(m-1) >> 1]);
        if (!m) 
            return 0.5 * (B[n >> 1] + B[(n-1) >> 1]);
        return 0.5 * (findKth(A, m, B, n, (m+n+1) >> 1) + findKth(A, m, B, n, (m+n+2) >> 1));
    }
private:
    int findKth(vector<int> &A, int m, vector<int> &B, int n, int k) {
        int p = findKthInA(A, m, B, n, k);
        if (p < m) 
            return A[p];
        p = findKthInA(B, n, A, m, k);
        if (p < n) 
            return B[p];
        return -1000000000;
    }
    int findKthInA(vector<int> &A, int m , vector<int> &B, int n, int k) {
        int l = 0, r = m-1;
        int q, s, p;
        while (l <= r) {
            p = (l + r) >> 1;
            q = k-p-2;
            s = k-p-1;
			if (s <= 0) {
				if ((p == k-1) && (A[p] <= B[0]))
					return p;
				r = p - 1;
			}
			else if (s >= n) {
				if ((n+p == k-1) && (A[p] >= B[n-1]))
					return p;
				l = p + 1;
			}
			else if (B[q] > A[p]) 
				l = p + 1;
			else if (B[s] < A[p]) 
				r = p - 1;
			else 
				return p;
        }
        return m;
    }
};