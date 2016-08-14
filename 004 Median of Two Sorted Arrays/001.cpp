class Solution {
public:
    double findMedianSortedArrays(vector<int> &A, vector<int> &B) {
        int lenA = A.size(), lenB = B.size();
        int idx1 = (lenA + lenB) / 2;
        int idx2 = (lenA + lenB - 1) / 2;
        return 0.5 * (findKth(A, B, idx1) + findKth(A, B, idx2));
    }
private:
    int findKth(vector<int> &A, vector<int> &B, int idx) {
        int lenA = A.size(), lenB = B.size();

        int p = findKthInA(A, B, idx);
        if (p >= 0)
            return A[p];

        return B[findKthInA(B, A, idx)];
    }
    int findKthInA(vector<int> &A, vector<int> &B, int idx) {
        int lenA = A.size(), lenB = B.size();
        int left = max(0, idx - lenB), right = min(idx, lenA - 1);

        while (left <= right) {
            int mid = (left + right) / 2;
            int idxLeft = idx - mid - 1;
            int idxRight = idx - mid;

			if ((idxLeft >= lenB) || (idxLeft >= 0) && (B[idxLeft] > A[mid]))
				left = mid + 1;
			else if ((idxRight < 0) || (idxRight < lenB) && (B[idxRight] < A[mid]))
				right = mid - 1;
			else
				return mid;
        }
        return -1;
    }
};
