class Solution {
public:
    double findMedianSortedArrays(vector<int> &A, vector<int> &B) {
        int len = A.size() + B.size();
        if (len & 1)
            return findKth(A, B, len >> 1);
        return 0.5 * (findKth(A, B, len >> 1) + findKth(A, B, (len - 1) >> 1));
    }
private:
    int findKth(vector<int> &A, vector<int> &B, int k) {
        int lenA = A.size(), lenB = B.size();

        int p = findKthInA(A, B, k);
        if (p < lenA)
            return A[p];

        p = findKthInA(B, A, k);
        if (p < lenB)
            return B[p];

        return INT_MAX;
    }
    int findKthInA(vector<int> &A, vector<int> &B, int k) {
        int lenA = A.size(), lenB = B.size();
        int left = 0, right = lenA - 1;

        while (left <= right) {
            int mid = (left + right) >> 1;
            int midLeft = k - mid - 1;
            int midRight = k - mid;

            if ((midLeft >= lenB) || (midLeft >= 0) && (B[midLeft] > A[mid]))
                left = mid + 1;
            else if ((midRight < 0) || (midRight < lenB) && (B[midRight] < A[mid]))
                right = mid - 1;
            else
                return mid;
        }
        return lenA;
    }
};
